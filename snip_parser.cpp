#include "snip_parser.hpp"
#include "utility.hpp"

#include <vector>
#include <iostream>

using namespace utility;

std::map<std::string,std::string> snip_db;

void find_snips(std::map<std::string,std::string> records, std::string &alignment) {
	std::vector<std::string> parts = split(alignment);
	std::vector<std::pair<int,char> > cigar = get_cigar_ops(parts[3]);

	int gene_pos = atoi(parts[2].c_str())-1;
	int read_pos = 0;

	std::string ref_sequence = records[parts[1]];
	std::string alignment_sequence = parts[4];

	int ref_len = ref_sequence.length();
	int read_len = alignment_sequence.length();

	char base_in_ref;
	char base_in_read;

	std::string pattern;

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

	if(!pattern.empty()) {
		if(snip_db.count(parts[1]) > 1) {
			snip_db[parts[1]] += pattern;
		}
		else {
			snip_db.insert(make_pair(parts[1], pattern));
		}
	}
}
