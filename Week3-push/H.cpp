#include "H.h"

using namespace std; 

void H::get_input() {
	cin >> N; 
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	string line; 
	getline(cin, line); 
	stringstream ss; 
	ss.str(line); 
	ss.clear(); 

	int token; 
	while (ss >> token) {
		numbers.push_back(token); 
	}
}

int H::calculate() {
	int k = 1; 
	bool satisfied = false; 
	while (!satisfied) {
		bool yes_or_no = check(k); 
		if (yes_or_no) {
			return k; 
		}
		else {
			k++; 
			if (k > numbers.size() / 2) {
				return -1; 
			}
		}
	}
}

bool H::check(int param) {
	vector<int> indexes; 
	int i = 1; 
	while (i * param <= numbers.size()) {
		indexes.push_back(i * param - 1); 
		i++; 
	}

	bool increasing = true; 

	for (int i = 0; i < indexes.size() - 1; i++) {
		int current = numbers[indexes[i]]; 
		int next = numbers[indexes[i + 1]]; 
		// current must be smaller than next. 
		if (current >= next) {
			increasing = false; 
		}
	}
	 
	return increasing; 
}