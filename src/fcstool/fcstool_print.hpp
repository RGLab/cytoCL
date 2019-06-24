/*
 * fcstool_print.hpp
 *
 *  Created on: Jun 20, 2019
 *      Author: wjiang2
 */

#ifndef SRC_FCSTOOL_FCSTOOL_PRINT_HPP_
#define SRC_FCSTOOL_FCSTOOL_PRINT_HPP_
#include "fcstool_config.hpp"
#define CHECK_FILE_OPT() \
		if(!has_file) \
		{ \
			cout << "Please specify the file to print." << endl; \
			return -1; \
		}
void fcs_print_summary(shared_ptr<MemCytoFrame> fr){
	auto keys = fr->get_keywords();
	auto params = fr->get_params();
	auto max_chnl = 1+ max_element(params.begin(), params.end(), [](auto &p1, auto &p2){return p1.channel.length() < p2.channel.length();})->channel.length();
	auto max_marker = 1 + max_element(params.begin(), params.end(), [](auto &p1, auto &p2){return p1.marker.length() < p2.marker.length();})->marker.length();
	cout << "cytoframe '" << keys["$FIL"] << "'" << endl;
	cout << "with " << keys["$TOT"] << " cells and " << params.size() << " observables: " << endl;
	cout << setw(max_chnl) << left << "name" ;
	cout << setw(max_marker) << right << "desc" ;
	cout << setw(10) << "minRange" ;
	cout << setw(10) << "maxRange" << endl;
	for(auto p :params)
	{
		cout << setw(max_chnl) << left << p.channel;
		cout << setw(max_marker) << right << p.marker;
		cout << setw(10) << right << setprecision(2) << p.min;
		cout << setw(10) << right << setprecision(2) << p.max;
		cout <<endl;
	}

	cout << keys.size() << " keywords" << endl;

}
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
	bool has_file = false;
	bool has_sub_opt = false;
	string fcs;
	shared_ptr<MemCytoFrame> fr;
	if (vm_sub.count("file")) {
		fcs = vm_sub["file"].as<string>();
		fr.reset(new MemCytoFrame(fcs, FCS_READ_PARAM()));
		fr->read_fcs_header();
		fr->get_channels();
		has_file = true;
	}
	if (vm_sub.count("summary")) {
		CHECK_FILE_OPT()
		has_sub_opt = true;
		fcs_print_summary(fr);
	}
	if (vm_sub.count("channel")) {
		CHECK_FILE_OPT()
		has_sub_opt = true;
		auto chnls = fr->get_channels();
		for(auto it = chnls.begin(); it != chnls.end()-1; it++)
			cout << "'" << *it << "' ";
		cout << "'" << chnls.back() << "'" << endl;

	}
	if (vm_sub.count("marker")) {
		CHECK_FILE_OPT()
		has_sub_opt = true;
		auto vec = fr->get_markers();
		for(auto it = vec.begin(); it != vec.end()-1; it++)
			cout << "'" << *it << "' ";
		cout << "'" << vec.back() << "'" << endl;
	}
	if(!has_sub_opt)
	{
		if(!has_file)
			cout << ls_desc;
		else
			fcs_print_summary(fr);
	}
	return 0;
}



#endif /* SRC_FCSTOOL_FCSTOOL_PRINT_HPP_ */
