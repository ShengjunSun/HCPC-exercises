#include "F.h" 

using namespace std; 

void F::get_input() {
	cin >> N;
	cin.ignore(1000, '\n'); 
	int Ai; 
	int Pi; 
	int Xi; 
	string line; 
	stringstream ss; 
	for (int i = 0; i < N; i++) {
		getline(cin, line); 
		ss.str(line); 
		ss.clear(); 
		
		ss >> Ai; 
		ss >> Pi; 
		ss >> Xi; 

		if (Xi - Ai > 0.5) {
			vector<int> shop_info;
			shop_info.push_back(Ai);
			shop_info.push_back(Pi);
			shop_info.push_back(Xi);
			shops.insert(shop_info);
		}		
	}
}

int F::calculate() {
	if (shops.size() == 0) {
		return -1; 
	}
	else {
		int answer = numeric_limits<int>::max();
		for (vector<int> shop : shops) {
			int price = shop[1]; 
			if (price < answer) {
				answer = price; 
			}
		}
		return answer; 
	}
}