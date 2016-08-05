#include "args.hpp"
#include <vector>
#include <stdlib.h>
#include <iostream>

void usage() {
        fprintf(stderr, "\n");
        fprintf(stderr, "Program: snipfinder \n");
        fprintf(stderr, "Usage: snipfinder [options] -amr_fp <fasta_file> -sampe/se <sam_file> -out_fp <output_file>\n\n");
        fprintf(stderr, "Options:\n\n");
        fprintf(stderr, "   -amr_fp STRING          amr database\n");
        fprintf(stderr, "   -samse STRING           single-end alignments\n");
        fprintf(stderr, "   -sampe STRING           paired-end alignments\n");
        fprintf(stderr, "   -b BOOLEAN              filter on unique alignments\n");
        fprintf(stderr, "   -out_fp STRING          output path\n\n");
}

cmd_args parse_command_line(int argc, const char *argv[]) {
	std::vector<std::string> args(argv, argv+argc);
	
	cmd_args arg;

	for(int i = 1; i < argc; i++) {
		if(args[i] == "-amr_fp") {
			arg.amr_fp = args[++i];
		}
		else if(args[i] == "-samse") {
			arg.sam_fp = argv[++i];		
			arg.samse = true;
		}
		else if(args[i] == "-sampe") {
			arg.sam_fp = argv[++i];
			arg.sampe = true;
		}
		else if(args[i] == "-out_fp") {
			arg.out_fp = argv[++i];
		}
		else if(args[i] == "-b") {
			arg.best = true;		
		}
		else {
			usage();
			exit(EXIT_FAILURE);						
		}
	}

	if(arg.samse) {
		arg.mode = arg.samse & arg.best ? 1 : 0;
	}
	else {
		arg.mode = arg.sampe && arg.best ? 3 : 2;
	}
	
	return arg;
}
