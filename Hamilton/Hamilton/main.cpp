#include <iostream>

int main(int argc, char** argv) {

	if (argc <= 1) {
		std::cout << "Usage: Hamilton [options]\nOptions:\n  -i <file>\t\tRead form <file>\n  -o <file>\t\tPlace the output into <file>\n  -s <node>\t\tSelect a starting <node>\n\n";
		std::cout << "Other Instuctions:\n  -Input file shoud be a text file consisting of a list of edges coded as such: <edge start node> -> <edge destination node> (<weight>) each edge should be divided by a comma ','. \n";
	}
	else {
        for (int i = 0; i < argc; i++) {
            std::string argument = argv[i];
			if (argument == "-i") {
				
			}
			else if (argument == "-s") {

			}
			else if (argument == "-o") {

			}
        }
	}

	return 0;
}