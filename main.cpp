#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "args.hpp"
#include "snip_parser.hpp"
#include "fasta_reader.hpp"
#include "sam_reader.hpp"

using namespace std;

void print_reads(const std::unordered_map<std::string,std::vector<std::string> > reads) {
	for(auto key = reads.begin(); key != reads.end(); ++key) {
		for(auto val = key->second.begin(); val != key->second.end(); ++val) {
			cout << *val << endl;
		}
	}
}

void print_records(map<string,string> &r) {
	for(auto it = r.begin(); it != r.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
}

void print_snip_db() {
	for(auto key = snip_db.begin(); key != snip_db.end(); ++key) {
		for(auto val = key->second.begin(); val != key->second.end(); ++val) {
			cout << key->first << " " << val->first << " " << val->second << endl;
		}
	}
}

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

	cout << args.mode << endl;

	//print_snip_db();	

	return 0;
}
