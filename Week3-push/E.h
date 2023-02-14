#ifndef CPP_E_H
#define CPP_E_H

#include <iostream>
#include <string>
#include <sstream>

class E {
private: 
	int N; 
	int A; 
	int B; 

public: 
	// override default constructor
	E() {
		get_input(); 
		std::cout << calculate() << std::endl;
	}
	
	void get_input(); 
	int calculate(); 
};

#endif
