#include "B.h"

void B::get_input() {
	std::cin >> this->input; 
}

std::string B::calculate() {
	if (this->input == 1) {
		return "YES"; 
	}
	else if (this->input <= 4) {
		return "NO"; 
	}
	else {
		return "Yes"; 
	}
}