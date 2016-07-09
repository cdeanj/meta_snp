#include "snip_writer.hpp"
#include <fstream>

snip_writer::snip_writer(std::string fp) : _fp(fp) {}

void snip_writer::write_snips(const std::map<std::string,std::pair<std::string,int> > &snip_db) {
	std::ofstream ofs(_fp);
	ofs << "Gene\t" << "Haplotype Pattern\t" << "Occurrence" << '\n';
	for(auto key = snip_db.begin(); key != snip_db.end(); ++key) {
		ofs << key->first << "\t" << key->second.first << "\t" << key->second.second << '\n';
	}
	ofs.close();
}
