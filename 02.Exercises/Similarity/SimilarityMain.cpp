#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

template<typename T>
std::set<T> readFromConsoleToSet() {
	std::string line;
	getline(std::cin, line);

	std::istringstream lineIn(line);
	T c;
	std::set<T> items;
	while (lineIn >> c) {
		items.insert(c);
	}

	return items;
}

bool areAlmostSame(const string& s1, const string& s2, int percent) {
	if (s1.size() != s2.size() || s1[0] != s2[0]) {
		return false;
	}

	double c = 1.0;

	for (size_t i = 1; i < s1.size(); i++) {
		if (s1[i] == s2[i]) {
			c++;
		}
	}

	double percentMatching = (c / s1.size()) * 100;

	return percentMatching <= percent;
}

int main() {
	set<string> words = readFromConsoleToSet<string>();

	string otherWord;
	int minPercentage;
	cin >> otherWord >> minPercentage;
	int c = 0;

	for (string s : words) {
		if (areAlmostSame(s, otherWord, minPercentage)) {
			c++; // hehe :}}
		}
	}

	cout << c << endl;

	return 0;
}