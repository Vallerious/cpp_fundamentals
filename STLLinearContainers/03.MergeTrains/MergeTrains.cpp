
#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <sstream>

std::set<int> readFromConsoleToSet() {
	std::string line;
	getline(std::cin, line);

	std::istringstream lineIn(line);
	int c;
	std::set<int> trainCars;
	while (lineIn >> c) {
		trainCars.insert(c);
	}

	return trainCars;
}

template<typename T>
std::priority_queue<T> mergeSetsWithPriority(const std::set<T>& s1, const std::set<T>& s2) {
	std::priority_queue<T> merged;

	for (T smth : s1) { merged.push(smth); }
	for (T smth : s2) { merged.push(smth); }

	return merged;
}

int main() {
	std::set<int> trainOnTrack1 = readFromConsoleToSet();
	std::set<int> trainOnTrack2 = readFromConsoleToSet();

	std::priority_queue<int> mergedTrain = mergeSetsWithPriority(trainOnTrack1, trainOnTrack2);
	std::ostringstream trainMarkedOrderStream;
	std::ostringstream trainCarsOrderStream;

	while (!mergedTrain.empty()) {
		int c = mergedTrain.top();
		trainCarsOrderStream << c << " ";
		mergedTrain.pop();

		if (trainOnTrack1.find(c) != trainOnTrack1.end()) {
			trainMarkedOrderStream << "A";
		}
		else if (trainOnTrack2.find(c) != trainOnTrack2.end()) {
			trainMarkedOrderStream << "B";
		}
	}

	std::cout << trainMarkedOrderStream.str() << std::endl;
	std::cout << trainCarsOrderStream.str() << std::endl;

	return 0;
}