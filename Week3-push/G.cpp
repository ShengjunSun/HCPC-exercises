#include "G.h"

using namespace std; 

string G::roll() {

	map<string, vector<double>> global_destinations; 

	int N; 
	cin >> N; 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string answer = "";

	string line; 
	
	while (N != 0) {

		map<string, vector<double>> destinations;
		vector<vector<double>> all_outputs;

		for (int i = 0; i < N; i++) {
			getline(cin, line); 
			if (destinations.find(line) == destinations.end()) {
				if (global_destinations.find(line) == global_destinations.end()) {
					global_destinations[line] = calculate(line); 
					destinations[line] = global_destinations[line]; 
 				}
				else {
					destinations[line] = global_destinations[line]; 
				}
			}
			all_outputs.push_back(destinations[line]); 
		}
		cin >> N;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// find average from the gathering of all outputs. 
		double average_x = 0.0;
		double average_y = 0.0; 
		double total_x = 0.0; 
		double total_y = 0.0; 
		for (vector<double> destination : all_outputs) {
			double x = destination[0]; 
			double y = destination[1]; 
			total_x += x; 
			total_y += y; 
		}
		average_x = total_x / all_outputs.size(); 
		average_y = total_y / all_outputs.size(); 

		answer += to_string(average_x); 
		answer += " "; 
		answer += to_string(average_y); 
		answer += " "; 

		// calculate the worst distance. 
		double worst_wtho_sqrt = 0.0; 
		for (auto pair : destinations) {
			vector<double> destination = pair.second; 
			double destination_x = destination[0]; 
			double destination_y = destination[1]; 

			double distance = pow((destination_x - average_x), 2)
				+ pow((destination_y - average_y), 2); 

			worst_wtho_sqrt = max(worst_wtho_sqrt, distance); 
		}
		answer += to_string(sqrt(worst_wtho_sqrt)); 
		answer += '\n'; 
	}

	return answer; 
}


vector<double> G::calculate(string param) {
	stringstream ss; 
	ss.str(param); 
	ss.clear(); 

	double start_x; 
	double start_y; 

	double end_x; 
	double end_y; 

	ss >> start_x; 
	ss >> start_y;

	end_x = start_x; 
	end_y = start_y; 

	double direction; 

	string instruction; 
	double degree; 

	while (ss >> instruction) {
		ss >> degree;
		if (instruction == "start") {
			direction = degree;
		}
		else if (instruction == "turn") {
			direction += degree; 
			// keep the direction within 0 to 360. 
			if (direction > 360) {
				int amt = static_cast<int>(direction); 
				int cycles = amt / 360; 
				direction = direction - (cycles * 360); 
			}
			else if (direction < 0) {
				int amt = static_cast<int>(direction); 
				int cycles = abs(amt / 360); 
				direction = direction + (cycles * 360); 
				direction = 360 + direction; 
			}
		}
		else {
			// walk
			double radians = (direction * M_PI) / 180; 
			end_x = end_x + degree * cos(radians); 
			end_y = end_y + degree * sin(radians); 
		}
	}

	vector<double> answer; 
	answer.push_back(end_x); 
	answer.push_back(end_y); 
	return answer; 
}