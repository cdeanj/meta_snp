#ifndef FASTA_READER_HPP
#define FASTA_READER_HPP

#include <vector>
#include <string>
#include <map>

class fasta_reader {
public:
	fasta_reader(std::string fp);
	std::map<std::string, std::string> read();
private:
	std::string _fp;
};

#endif // FASTA_READER_HPP
