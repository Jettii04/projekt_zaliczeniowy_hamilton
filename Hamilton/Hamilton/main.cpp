#include <iostream>
#include "graph.h"

int main(int argc, char** argv) {
	try {
		if (argc <= 1) {
			std::cout << "Usage: Hamilton [options]\nOptions:\n  -i <file>\t\tRead form <file>\n  -o <file>\t\tPlace the output into <file>\n  -s <node>\t\tSelect a starting <node>\n\n";
			std::cout << "Other Instuctions:\n  -Input file shoud be a text file consisting of a list of edges coded as such: <edge start node> -> <edge destination node> (<weight>) Edges should be separated by a comma ','. \n";
		}
		else {
			for (int i = 0; i < argc; i++) {
				std::string argument = argv[i];
				if (argument == "-i") {
					if (i + 1< argc) {
						Graph inputGraph;
						std::string fileName = argv[i + 1];
						inputGraph.read_form_file(fileName);
						std::cout << "Input Graph:\n";
						inputGraph.print();
					}
					else {
						throw 1;
					}
				}
				else if (argument == "-s") {
					std::cout << "-s Work in progress\n";
				}
				else if (argument == "-o") {
					std::cout << "-o Work in progress\n";

				}
			}
		}
	}
	catch (int errorCode) {
		if (errorCode == 1) {
			std::cout << "Error! : No file name specified";
		}
	}
	catch (std::invalid_argument e) {
		std::cout << "Error! : Incorrect data";
	}
	catch(std::system_error e){
		std::cout << "Error! : " << e.what();
	}
	catch (std::exception e) {
		std::cout << "Error! : " << e.what();
	}catch(...) {
		std::cout << "Unknown error!";
	}

	return 0;
}