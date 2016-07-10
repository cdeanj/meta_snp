#ifndef SNIP_PARSER_HPP
#define SNIP_PARSER_HPP

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

#include "utility.hpp"

std::map<std::string,std::vector<std::pair<std::string,int> > > snip_db;

// TODO: Update function to return iterator to found element, so we don't have to traverse
// map twice when we update haplotype occurrence
bool pattern_exists(const std::string &haplotype_pattern, const std::string &key) {
	std::map<std::string,std::vector<std::pair<std::string,int> > >::iterator k = snip_db.find(key);
	if(k != snip_db.end()) {
		for(auto v = k->second.begin(); v != k->second.end(); ++v) {
			if(v->first == haplotype_pattern) {
				return true;
			}
		}
	}
	return false;
}

void update_count(const std::string &haplotype_pattern, const std::string &key) {
	std::map<std::string,std::vector<std::pair<std::string,int> > >::iterator k = snip_db.find(key);
        if(k != snip_db.end()) {
                for(auto v = k->second.begin(); v != k->second.end(); ++v) {
                        if(v->first == haplotype_pattern) {
				v->second++;
                        }
                }
        }
}

template <class Iter>
void find_snips(std::map<std::string,std::string> &records, Iter start, Iter stop) {
	std::string pattern;
	std::vector<std::string> parts;

	while(start != stop) {
        	parts = utility::split(*start);
        	std::vector<std::pair<int,char> > cigar = utility::get_cigar_ops(parts[3]);

        	int gene_pos = atoi(parts[2].c_str())-1;
        	int read_pos = 0;

        	std::string ref_sequence = records[parts[1]];
        	std::string alignment_sequence = parts[4];

        	int ref_len = ref_sequence.length();
        	int read_len = alignment_sequence.length();

        	char base_in_ref;
        	char base_in_read;

        	for(int i = 0; i < cigar.size(); i++) {
                	int occurrence = cigar[i].first;
                	char operation = cigar[i].second;

                	if(operation == 'M' || operation == '=') {
                        	for(int k = 0; k < occurrence; k++) {
                                	if(gene_pos >= ref_len || read_pos >= read_len) {
                                        	break;
                                	}

                                	base_in_ref = ref_sequence[gene_pos];
                                	base_in_read = alignment_sequence[read_pos];

                                	if(base_in_ref != base_in_read) {
                                        	pattern += std::to_string(gene_pos+1) + std::string(1,base_in_ref) + "->" + std::string(1,base_in_read) + ":";
                                	}
                                	++gene_pos;
                                	++read_pos;
                        	}
                	}
                	else if(operation == 'I') {
                        	read_pos += occurrence;
                        	gene_pos += occurrence;
                	}
                	else if(operation == 'S') {
                        	read_pos += occurrence;
                	}
                	else if(operation == 'N') {
                        	gene_pos += occurrence;
                	}
                	else if(operation == 'P') {
                        	read_pos += occurrence;
                        	gene_pos += occurrence;
                	}
                	else if(operation == 'D') {
                        	gene_pos += occurrence;
                	}
			else if(operation == 'X') {
                        	read_pos += occurrence;
                        	gene_pos += occurrence;
                	}
                	else if(operation == 'H') {
                        	break;
                	}
                	else {
                        	std::cout << "Operation " << operation << " not handled." << std::endl;
                	}
        	}
		*start++; // jump to next alignment in pair
	}
	if(!pattern.empty()) {
		if(pattern_exists(pattern, parts[1])) {
			update_count(pattern, parts[1]);
		}
		else {
			snip_db[parts[1]].push_back(std::pair<std::string,int>(pattern,1));
		}
        }
}


#endif // SNIP_PARSER_HPP
