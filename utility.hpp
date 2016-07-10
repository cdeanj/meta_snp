#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <map>
#include <string>
#include <vector>
#include <utility>

extern std::map<std::string,std::vector<std::pair<std::string,int> > > snip_db;

namespace utility {
	std::vector<std::string> split(std::string &alignment);
	std::vector<std::string> split_parts(const std::vector<std::string> &parts);
	std::string concatenate_parts(const std::vector<std::string> &parts);
	std::vector<std::pair<int,char> > get_cigar_ops(const std::string &cigar);
	bool is_valid_se_alignment(const std::vector<std::string> &parts);
	bool is_valid_pe_alignment(const std::vector<std::string> &parts);
	bool is_alignment_unique(const std::string &alignment);
	bool is_good_rname(const std::string &rname);
	bool is_good_cigar(const std::string &cigar);
	bool is_good_seq(const std::string &seq);
	bool read_paired(const int flag);
	bool read_mapped(const int flag);
	bool mate_mapped(const int flag);
	bool is_good_pos(const int pos);
}

#endif // UTILITY_HPP
