#ifndef ARGS_H
#define ARGS_H

#include <string>
#include <vector>

struct cmd_args {
	std::string amr_fp;
	std::string sam_fp;
	std::string out_fp;

	bool sampe;
	bool samse;
	bool best;
	int mode;
};

static inline cmd_args
parse_command_line(int argc, const char *argv[]) {
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
			exit(EXIT_FAILURE);						
		}
	}
	
	return arg;
}

#endif //ARGS_H
