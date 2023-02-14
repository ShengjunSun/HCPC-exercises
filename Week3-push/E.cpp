#include "E.h"

using namespace std; 

void E::get_input() {
	string line; 
	getline(cin, line); 
	stringstream ss; 
	ss.str(line); 
	ss.clear(); 

	ss >> this->N; 
	ss >> this->A; 
	ss >> this->B; 
}

int E::calculate() {
	int amt = N / (A + B); 
	int remainder = N % (A + B); 
	int answer = 0; 
	if (amt >= 1) {
		answer += amt * A; 
	}
	if (remainder < A) {
		answer += remainder; 
	}
	else {
		answer += A; 
	}
	return answer; 
}