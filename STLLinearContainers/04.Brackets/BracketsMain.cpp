#include <string>
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <queue>

bool checkPrecedence(std::stack<char>& brackets, char c) {
	std::stack<char> temp;

	while (!brackets.empty()) {
		char tempChar = brackets.top();
		brackets.pop();
		temp.push(tempChar);

		if (c == '{' && (tempChar == '(' || tempChar == '[')) {
			return false;
		}
		else if (c == '[' && tempChar == '(') {
			return false;
		}
	}

	std::stack<char> newBrackets;

	while (!temp.empty()) {
		newBrackets.push(temp.top());
		temp.pop();
	}

	brackets = newBrackets;

	return true;
}

bool validateBrackets(std::string expression) {
	std::stack<char> brackets;
	std::set<char> openingBrackets = {'{', '[', '('};
	std::set<char> closingBrackets = { '}', ']', ')' };
	std::map<char, char> openClosingBrackets = {
		{'{', '}'}, {'[', ']'}, {'(', ')'}
	};

	for (char c : expression) {
		bool isOpening = openingBrackets.find(c) != openingBrackets.end();

		if (isOpening) {
			brackets.push(c);

			if (!checkPrecedence(brackets, c)) {
				return false;
			}
		}
		else {
			char lastChar = brackets.top();
			brackets.pop();

			if (openClosingBrackets[lastChar] != c) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	std::string line;
	getline(std::cin, line);
	bool isValid = validateBrackets(line);

	std::cout << (isValid ? "valid" : "invalid") << std::endl;

	return 0;
}