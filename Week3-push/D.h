#ifndef CPP_D_H
#define CPP_D_H

#include <iostream>
#include <string>
#include <sstream>

class D {
private: 
	int amt_of_stick; 
	int amt_of_cross; 

public: 
	D() {
		get_input(); 
		std::cout << calculate() << std::endl; 
	}

	void get_input(); 
	std::string calculate(); 
};

#endif
