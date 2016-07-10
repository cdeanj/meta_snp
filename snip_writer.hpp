#ifndef SNIP_WRITER_HPP
#define SNIP_WRITER_HPP

#include <map>
#include <string>
#include <utility>

class snip_writer {
	snip_writer(std::string fp);
	void write_snips(const std::map<std::string,std::pair<std::string,int> > &snip_db);

private:
	std::string _fp;
};


#endif // SNIP_WRITER_HPP
