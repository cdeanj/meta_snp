#ifndef SNIP_PARSER_H
#define SNIP_PARSER_H

template <class Iter>
void find_snips(Iter start, Iter end) {
	std::cout << *start << std::endl;
	*start++;
	std::cout << *start << std::endl;
	*start++;
	std::cout << *start << std::endl;
}



#endif // SNIP_PARSER_H
