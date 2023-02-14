#ifndef CPP_H_H
#define CPP_H_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

class H {
private: 
	int N; 
	std::vector<int> numbers; 

public: 
	// override the default constructor
	H() {
		get_input(); 
		std::cout << calculate() << std::endl; 
	}
	void get_input(); 
	int calculate(); 
	bool check(int param); 
};

#endif
