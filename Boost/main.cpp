#include <iostream>

#include <boost\program_options\options_description.hpp>
#include <boost\program_options\option.hpp>

namespace po = boost::program_options;

int main() {
	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help messsage")
		;
	return 0;
}
