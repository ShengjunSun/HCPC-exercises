#ifndef CPP_B_H
#define CPP_B_H

#include <iostream>
#include <string>

class B {
private: 
	int input;

public: 
	B() {
		get_input(); 
		std::cout << calculate() << std::endl; 
	}

	void get_input(); 
	std::string calculate(); 
};

#endif