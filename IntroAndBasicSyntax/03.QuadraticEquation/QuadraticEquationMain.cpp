#include <iostream>
#include <string>

#include "Quadratic.h"

const std::string NO_ROOTS_MESSAGE = "no roots";

int main() {
	double a, b, c;

	std::cin >> a >> b >> c;

	Quadratic q{ a, b, c };

	if (q.hasNoRoots()) {
		std::cout << NO_ROOTS_MESSAGE << std::endl;
	}
	else if (q.hasOneRoot()) {
		std::cout << q.getPositiveQuadraticValue() << std::endl;
	}
	else {
		std::cout << q.getNegativeQuadraticValue() << " " << q.getPositiveQuadraticValue() << std::endl;
	}

	return 0;
}
