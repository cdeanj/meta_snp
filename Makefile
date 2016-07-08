output: main.o fasta_reader.o sam_reader.o utility.o snip_parser.o
	g++ -std=c++11 main.o fasta_reader.o sam_reader.o utility.o snip_parser.o -o metasnp
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
fasta_reader.o: fasta_reader.cpp
	g++ -c -std=c++11 fasta_reader.cpp
sam_reader.o: sam_reader.cpp
	g++ -c -std=c++11 sam_reader.cpp
utility.o: utility.cpp
	g++ -c -std=c++11 utility.cpp
snip_parser.o: snip_parser.cpp
	g++ -c -std=c++11 snip_parser.cpp
clean:
	rm *.o metasnp
