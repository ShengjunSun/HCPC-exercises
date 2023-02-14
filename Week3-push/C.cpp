#include "C.h"

using namespace std; 

string C::roll() {

	string line; 
	std::getline(cin, line); 

	stringstream ss;
	double x1; 
	double y1; 
	double x2; 
	double y2; 
	double p; 

	string output = ""; 
	
	while (line != "0") {
		ss.str(line);
		ss.clear();
		ss >> x1; 
		ss >> y1; 
		ss >> x2; 
		ss >> y2; 
		ss >> p; 
		vector<double> input; 
		input.push_back(x1); 
		input.push_back(y1); 
		input.push_back(x2); 
		input.push_back(y2); 
		input.push_back(p); 

		if (this->inputs.find(input) != this->inputs.end()) {
			// found
			output = output + to_string(this->inputs[input]) + '\n';
		}
		else {
			// not found
			double answer = calculate(x1, y1, x2, y2, p); 
			output = output + to_string(answer) + '\n'; 
			this->inputs[input] = answer; 
		}
		std::getline(cin, line); 
	}	
	return output; 
}

double C::calculate(double x1, double y1, double x2, double y2, double p) {
	double factor1 = pow(std::abs(x1 - x2), p);
	double factor2 = pow(std::abs(y1 - y2), p);
	double power = 1.0 / p;
	return pow((factor1 + factor2), power);
}