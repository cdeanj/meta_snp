#ifndef SAM_READER_H
#define SAM_READER_H

#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

class sam_reader {
public:
	sam_reader(std::string fp, int mode);
	std::unordered_map<std::string,std::vector<std::string> > read();

private:
	void read_paired(std::unordered_map<std::string,std::vector<std::string> > &reads);
	void read_single(std::unordered_map<std::string,std::vector<std::string> > &reads);	
	void read_paired_unique(std::unordered_map<std::string,std::vector<std::string> > &reads);
        void read_single_unique(std::unordered_map<std::string,std::vector<std::string> > &reads);
	std::string _fp;
	int _mode;
};

#endif // SAM_READER_H
