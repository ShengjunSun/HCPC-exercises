#ifndef CPP_F_H
#define CPP_F_H

#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <limits>

class F {
private: 
	int N; 
	std::set<std::vector<int>> shops; 

public: 
	// override the default constructor
	F() {
		get_input();
		std::cout << calculate() << std::endl;
	}

	void get_input(); 
	int calculate(); 
};

#endif
