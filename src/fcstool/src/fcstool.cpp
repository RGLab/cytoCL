//============================================================================
// Name        : cytoCL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "fcstool_help_msg.hpp"
CYTOLIB_INIT();

#include "fcstool_print.hpp"

int main(int argc, char ** argv) {
	// Declare the supported options.
	po::options_description desc("");
	desc.add_options()
	    ("help", "produce help message")
	    ("command", po::value<string>(), "subcommand")
		("subargs", po::value<std::vector<std::string> >(), "Arguments for command");
	po::positional_options_description pos;
	pos.add("command", 1).
		add("subargs", -1);


	po::variables_map vm;
	po::parsed_options parsed = po::command_line_parser(argc, argv).
	    options(desc).
	    positional(pos).
	    allow_unregistered().
	    run();

	po::store(parsed, vm);
	po::notify(vm);

	//parse subcmd first
	if (vm.count("command")) {
	    string cmd = vm["command"].as<string>();

		// Collect all the unrecognized options from the first pass. This will include the
		// (positional) command name, so we need to erase that.
		std::vector<std::string> opts = po::collect_unrecognized(parsed.options, po::include_positional);
		opts.erase(opts.begin());
		if(cmd == "print")
		{
			return fcstool_print(opts);
		}else
		{
			cout << "unsupported subcommand: '" << cmd << "'" << endl;
			return -1;
		}
	}
	else
	{
//		if (vm.count("help")) {
				print_fcstool_help_msg();
//				return 1;
//			}
	}


	return 0;
}
