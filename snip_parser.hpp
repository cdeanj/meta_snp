#ifndef SNIP_PARSER_H
#define SNIP_PARSER_H

#include <map>
#include <string>

extern std::map<std::string,std::string> snip_db;

void find_snips(const std::map<std::string,std::string> records, std::string &alignment);


#endif // SNIP_PARSER_H
