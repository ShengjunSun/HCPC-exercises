#include "D.h"

using namespace std; 

void D::get_input() {
	string first_line; 
	getline(cin, first_line); 
	stringstream ss; 
	ss.str(first_line); 
	ss.clear(); 

	ss >> this->amt_of_stick; 
	ss >> this->amt_of_cross; 
}

string D::calculate() {
	int token = this->amt_of_stick / this->amt_of_cross;
	int parity = token % 2;
	if (parity == 0) {
		return "NO";
	}
	else {
		return "YES";
	}
}