#include "snip_writer.hpp"
#include <fstream>

snip_writer::snip_writer(std::string fp) : _fp(fp) {}

void snip_writer::write_snips(const std::map<std::string,std::vector<std::pair<std::string,int> > > &snip_db) {
	std::ofstream ofs(_fp);
	ofs << "Gene\t" << "Haplotype Pattern\t" << "Occurrence" << '\n';
	for(auto key = snip_db.begin(); key != snip_db.end(); ++key) {
		for(auto val = key->second.begin(); val != key->second.end(); ++val) {
			ofs << key->first << "\t" << val->first << "\t" << val->second << '\n';
		}
	}
	ofs.close();
}
