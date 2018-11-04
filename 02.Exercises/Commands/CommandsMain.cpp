#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

class Calculator {
private:
	stack<int> mem;
public:
	void insert(int n) {
		mem.push(n);
	}

	void sum() {
		int n1 = mem.top();
		mem.pop();
		int n2 = mem.top();
		mem.pop();

		mem.push(n1 + n2);
	}

	void subtract() {
		int n1 = mem.top();
		mem.pop();
		int n2 = mem.top();
		mem.pop();

		mem.push(n1 - n2);
	}

	void concat() {
		int n1 = mem.top();
		mem.pop();
		int n2 = mem.top();
		mem.pop();

		ostringstream strBuilder;
		strBuilder << n2 << n1;

		istringstream strBuilderIn(strBuilder.str());

		int concatenated;
		strBuilderIn >> concatenated;

		mem.push(concatenated);
	}

	void discard() {
		mem.pop();
	}

	stack<int> getMemory() const {
		return this->mem;
	}
};

template<typename T>
void printStackReversed(stack<T> someStack) {
	stack<T> temp;

	while (!someStack.empty()) {
		temp.push(someStack.top());
		someStack.pop();
	}

	while (!temp.empty()) {
		cout << temp.top() << endl;
		temp.pop();
	}
}

int main() {
	Calculator c;

	string command;

	while (true) {
		cin >> command;

		if (command == "end") break;

		if (command == "sum") {
			c.sum();
		}
		else if (command == "subtract") {
			c.subtract();
		}
		else if (command == "concat") {
			c.concat();
		}
		else if (command == "discard") {
			c.discard();
		}
		else {
			istringstream numberIn(command);
			int n;
			numberIn >> n;

			c.insert(n);
		}
	}

	printStackReversed(c.getMemory());

	return 0;
}