#include "A.h"

using namespace std;

void A::get_input() {
	cin >> this->input; 
}

int A::calculate() {
	vector<int> binary; 
	int input_cp = this->input; 
	int remainder; 
	while (input_cp != 0) {
		remainder = input_cp % 2;
		input_cp = input_cp / 2; 
		binary.push_back(remainder);
	}

	// now let's convert the 'binary' back to decimal.
	int length = binary.size(); 
	int power = 0; 
	int answer = 0; 
	for (int i = length - 1; i >= 0; i--) {
		if (binary[i] == 1) {
			answer += pow(2, power); 
		}
		power++; 
	}

	return answer; 
}