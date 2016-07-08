#include <fstream>
#include <iostream>

#include "sam_reader.hpp"
#include "utility.hpp"

using namespace utility;

sam_reader::sam_reader(std::string fp, int mode) : _fp(fp), _mode(mode) {}

std::unordered_map<std::string,std::vector<std::string> > sam_reader::read() {
	std::unordered_map<std::string,std::vector<std::string> > alignments;
	if(_mode == 0) {
		read_single(alignments);
	}
	else if(_mode == 1) {
		read_single_unique(alignments);
	}
	else if(_mode == 2) {
		read_paired(alignments);
	}
	else {
		read_paired_unique(alignments);
	}
	
	return alignments;
}

void sam_reader::read_single(std::unordered_map<std::string,std::vector<std::string> > &alignments) {
	std::ifstream ifs(_fp);
	if(!ifs) {
		std::cerr << "Unable to open sam file" << std::endl;
	}
	std::string line;
	while(std::getline(ifs, line)) {
		if(line[0] == '@') {
			continue;
		}
		std::vector<std::string> parts = split(line);
		if(is_valid_se_alignment(parts)) {
			std::vector<std::string> n_parts = split_parts(parts);
			alignments[parts[0]].push_back(concatenate_parts(n_parts));
		}
	}
}

void sam_reader::read_single_unique(std::unordered_map<std::string,std::vector<std::string> > &alignments) {
	std::ifstream ifs(_fp);
        if(!ifs) {
                std::cerr << "Unable to open sam file" << std::endl;
        }
        std::string line;
        while(std::getline(ifs, line)) {
                if(line[0] == '@') {
                        continue;
                }
                std::vector<std::string> parts = split(line);
                if(is_valid_se_alignment(parts) && is_alignment_unique(line)) {
                        std::vector<std::string> n_parts = split_parts(parts);
                        alignments[parts[0]].push_back(concatenate_parts(n_parts));
                }
        }
}

void sam_reader::read_paired(std::unordered_map<std::string,std::vector<std::string> > &alignments) {
	std::ifstream ifs(_fp);
        if(!ifs) {
                std::cerr << "Unable to open sam file" << std::endl;
        }
        std::string line;
        while(std::getline(ifs, line)) {
                if(line[0] == '@') {
                        continue;
                }
                std::vector<std::string> parts = split(line);
                if(is_valid_pe_alignment(parts)) {
                        std::vector<std::string> n_parts = split_parts(parts);
                        alignments[parts[0]].push_back(concatenate_parts(n_parts));
                }
        }
}

void sam_reader::read_paired_unique(std::unordered_map<std::string,std::vector<std::string> > &alignments) {
	std::ifstream ifs(_fp);
        if(!ifs) {
                std::cerr << "Unable to open sam file" << std::endl;
        }
        std::string line;
        while(std::getline(ifs, line)) {
                if(line[0] == '@') {
                        continue;
                }
                std::vector<std::string> parts = split(line);
                if(is_valid_pe_alignment(parts) && is_alignment_unique(line)) {
                        std::vector<std::string> n_parts = split_parts(parts);
                        alignments[parts[0]].push_back(concatenate_parts(n_parts));
                }
        }
}
