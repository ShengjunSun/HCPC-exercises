#ifndef CPP_G_H
#define CPP_G_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>
#include <limits>

class G {

public: 
	// override defaulut constructor
	G() {
		std::cout << roll() << std::endl; 
	}

	std::string roll(); 
	std::vector<double> calculate(std::string param); 
};

#endif
