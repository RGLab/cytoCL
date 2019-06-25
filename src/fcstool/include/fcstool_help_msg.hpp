/*
 * fcstool_help.hpp
 *
 *  Created on: Jun 19, 2019
 *      Author: wjiang2
 */

#ifndef SRC_FCSTOOL_FCSTOOL_HELP_MSG_HPP_
#define SRC_FCSTOOL_FCSTOOL_HELP_MSG_HPP_
#include "fcstool_config.hpp"
void print_fcstool_help_msg(){
		cout << "usage: fcstool [--version] [--help] <subcommand> [<args>]\n\n";
		cout << "These are common fcstool subcommand:\n";
		cout << endl;
		cout << "init \tCreate a new subdirectory and parse all the fcs files into structured format (e.g. h5)\n";
		cout << "check \tperform various QC checks across files\n";
		cout << "print \tprint the content of single fcs file\n";
		cout << "diff \tShow difference between two files\n";
		cout << "merge \tJoin two or more files together\n";
		cout << "add \tadd the content of single h5 file\n";
		cout << "Rm \tremove the content of single h5 file\n";
		cout << endl;
	cout << "see 'fcstool <command>' to read about a specific subcommand.\n";

}


#endif /* SRC_FCSTOOL_FCSTOOL_HELP_MSG_HPP_ */
