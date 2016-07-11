#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "args.hpp"
#include "snip_parser.hpp"
#include "fasta_reader.hpp"
#include "sam_reader.hpp"
#include "snip_writer.hpp"

using namespace std;

int main(int argc, const char *argv[]) {
	struct cmd_args args;
	args = parse_command_line(argc, argv);

	fasta_reader fr(args.amr_fp);
	map<string,string> records = fr.read();

	sam_reader sr(args.sam_fp, args.mode);
	std::unordered_map<std::string,std::vector<std::string> > alignments = sr.read();

	for(auto key = alignments.begin(); key != alignments.end(); ++key) {
		find_snips(records, key->second.begin(), key->second.end());
	}

	snip_writer sw(args.out_fp); 
	sw.write_snips(snip_db);

	return 0;
}
