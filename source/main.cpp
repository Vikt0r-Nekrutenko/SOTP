#include <iostream>

#include "container.h"
#include "xml_node.h"
#include "xml_parser.h"
#include "calculator.h"
#include "xml_writer.h"

using namespace xml_utilites;

int main(int argc, char** argv) {
	
	xml_parser parser("intrvs.xml");
	parser.Parse();
	
	container container_of_primes;	
	calculator calc(container_of_primes);
	
	clock_t btime = clock();
	calc.startCalculation( parser.getIntervals() );
	clock_t etime = clock();
	
	xml_node root("<root>"), prs("primes", container_of_primes.getStr());
	root.addChildNode(prs);
	
	xml_writer writer("primes.xml");
	writer.Write(root);
	
	std::cout << "\nTime for calculation: " << (etime - btime)/1000.f << "seconds\t CPP:" << __cplusplus << std::endl;
	system("pause");
	return 0;
}
