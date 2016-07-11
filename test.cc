#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	map<string,map<string,int> > m;

	m["A"].insert(make_pair("ACGT",1));
	m["B"].insert(make_pair("ACGTT",1));

	/*if(m["B"].find("ACGT") != m["B"].end()) {
		cout << "found" << endl;
	}
	else {
		cout << "not found" << endl;
	}*/

	m["A"]["ACGT"]+=1;

	for(auto key = m.begin(); key != m.end(); ++key) {
		for(auto val = key->second.begin(); val != key->second.end(); ++val) {
			cout << val->second << " " << key->first << " ";
		}
		cout << endl;
	}


	return 0;
}
