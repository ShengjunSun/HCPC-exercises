#ifndef CPP_A_H
#define CPP_A_H

#include <iostream>
#include <vector>
#include <cmath>

class A {
private:
	int input; 

public: 
	// override default constructor
	A() {
		get_input(); 
		std::cout << calculate() << std::endl;
	}

	void get_input(); 
	int calculate(); 
};

#endif
