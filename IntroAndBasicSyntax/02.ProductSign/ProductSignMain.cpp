#include <iostream>

int main() {
	double a, b, c;
	int minusSignCount = 0;

	std::cin >> a >> b >> c;

	if (a < 0) {
		minusSignCount++;
	}

	if (b < 0) {
		minusSignCount++;
	}

	if (c < 0) {
		minusSignCount++;
	}

	if (minusSignCount % 2 == 1) {
		std::cout << "-" << std::endl;
	}
	else {
		std::cout << "+" << std::endl;
	}

	return 0;
}
