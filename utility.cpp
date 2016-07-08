#include "utility.hpp"

#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <iostream>

namespace utility {
	std::vector<std::string> split(std::string &alignment) {
		std::string field;
		std::istringstream ss(alignment);
		std::vector<std::string> parts;
		while(ss >> field) {
			parts.push_back(field);
		}
		return parts;
	}

	std::vector<std::string> split_parts(const std::vector<std::string> &parts) {
		std::vector<std::string> important_parts;
		important_parts.push_back(parts[1]);
		important_parts.push_back(parts[2]);
		important_parts.push_back(parts[3]);
		important_parts.push_back(parts[5]);
		important_parts.push_back(parts[9]);
		return important_parts;
	}

	std::string concatenate_parts(const std::vector<std::string> &parts) {
		std::string s;
		for(auto it = parts.begin(); it != parts.end(); ++it) {
			s += *it + " ";
		}
		return s;
	}

	bool is_valid_se_alignment(const std::vector<std::string> &parts) {
		if(!(read_mapped(atoi(parts[1].c_str()))))
                        return false;
		if(!(is_good_rname(parts[2])))
			return false;
		if(!(is_good_pos(atoi(parts[3].c_str()))))
                        return false;
		if(!(is_good_cigar(parts[5]))) 
			return false;
		if(!(is_good_seq(parts[9])))
			return false;
		
		return true;
	}

	bool is_valid_pe_alignment(const std::vector<std::string> &parts) {
		if(!(read_mapped(atoi(parts[1].c_str()))))
                        return false;
                if(!(mate_mapped(atoi(parts[1].c_str()))))
                        return false;
		if(!(is_good_rname(parts[2])))
                        return false;
                if(!(is_good_cigar(parts[5])))
                        return false;
                if(!(is_good_seq(parts[9])))
                        return false;
		if(!(read_paired(atoi(parts[1].c_str()))))
			return false;
                if(!(is_good_pos(atoi(parts[3].c_str()))))
                        return false;

		return true;
	}

	std::vector<std::pair<int,char> > get_cigar_ops(const std::string &cigar) {
		int count;
		char operation;
		std::vector<std::pair<int,char> > vp;
		std::istringstream ss(cigar);
		while(ss >> count >> operation) {
			vp.push_back(std::make_pair(count,operation));
		}
		return vp;
	}

	bool is_good_rname(const std::string &rname) {
		return rname.compare("*") != 0;
	}

	bool is_good_cigar(const std::string &cigar) {
		return cigar.compare("*") != 0;
	}

	bool is_good_seq(const std::string &seq) {
		return seq.compare("*") != 0;
	}

	bool read_paired(const int flag) {
		return (flag & 1) == 1;
	}

	bool read_mapped(const int flag) {
		return (flag & 4) == 0;
	}

	bool mate_mapped(const int flag) {
		return (flag & 8) == 0;
	}
	
	bool is_good_pos(const int pos) {
		return pos != 0;
	}

	bool is_alignment_unique(const std::string &alignment) {
		return alignment.find("XT:A:U") != std::string::npos;
	}
}
