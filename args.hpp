#ifndef ARGS_HPP
#define ARGS_HPP

#include <string>

struct cmd_args {
	std::string amr_fp;
	std::string sam_fp;
	std::string out_fp;

	bool sampe = false;
	bool samse = false;
	bool best = false;
	int mode;
};

void usage();
cmd_args parse_command_line(int argc, const char *argv[]);

#endif //ARGS_HPP
