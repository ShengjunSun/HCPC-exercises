#ifndef CPP_C_H
#define CPP_C_H

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

class C {
private: 
	std::map<std::vector<double>, double> inputs; 

public: 
	C() {
		std::cout << roll() << std::endl; 
	}

	std::string roll(); 
	double calculate(double x1, double y1, double x2, double y2, double p); 
};

#endif
