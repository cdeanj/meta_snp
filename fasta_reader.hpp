#ifndef FASTA_READER_H
#define FASTA_READER_H

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

#endif // FASTA_READER_H
