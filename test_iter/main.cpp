#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "snip_parser.hpp"

using namespace std;

int main() {
	map<string,vector<string> > m;
	m["A"].push_back("ACGT");
	m["A"].push_back("TGCA");
	m["A"].push_back("CGGT");

	for(auto key = m.begin(); key != m.end(); ++key) {
		find_snips(key->second.begin(), key->second.end());
	}



	return 0;
}
