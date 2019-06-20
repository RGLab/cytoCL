/*
 * fcstool_print.hpp
 *
 *  Created on: Jun 20, 2019
 *      Author: wjiang2
 */

#ifndef SRC_FCSTOOL_FCSTOOL_PRINT_HPP_
#define SRC_FCSTOOL_FCSTOOL_PRINT_HPP_
#include "fcstool_config.hpp"
int fcstool_print(std::vector<std::string> opts){
	// ls command has the following options:
	po::variables_map vm_sub;

	po::options_description ls_all("");
	po::options_description ls_desc("print the content of single fcs file\n\n"
									"usage: fcstool print [OPTIONS] file\n\n"
									"OPTIONS");
	ls_desc.add_options()
		("summary,s", "summary of fcs")
		("channel,c", "print channels")
		("marker,m", "print markerss")
		("keyword,k", "print keywords")
		("data,d", "print data values")
		("keyword,k", "print keywords");

	ls_all.add(ls_desc).add_options()
		("file", po::value<std::string>(), "file to print");

	po::positional_options_description pos;
	pos.add("file", 1);

	// Parse again...
	po::store(po::command_line_parser(opts).options(ls_all).positional(pos).run(), vm_sub);
	po::notify(vm_sub);
	if (vm_sub.count("help")) {
		cout << ls_desc;
		return 1;
	}
	string fcs;
	if (vm_sub.count("file")) {
		fcs = vm_sub["file"].as<string>();
		MemCytoFrame fr(fcs);

		return 1;
	}
	if (vm_sub.count("summary")) {
		cout << "cytoframe" << endl;
		return 1;
	}
	if (vm_sub.count("channel")) {
		cout << "channel" << endl;
		return 1;
	}
	if (vm_sub.count("marker")) {
		cout << "marker" << endl;
		return 1;
	}
	cout << ls_desc;
	return 0;
}



#endif /* SRC_FCSTOOL_FCSTOOL_PRINT_HPP_ */
