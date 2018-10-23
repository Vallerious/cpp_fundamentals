#include <iostream>
#include <math.h>

int main() {
	int maxIntegerBits = (sizeof(int) * 8) - 1;
	int maxIntegerValue = pow(2, maxIntegerBits) - 1;

	int n, min = maxIntegerValue, max = -maxIntegerValue;

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int c;

		std::cin >> c;

		if (c > max) {
			max = c;
		}

		if (c < min) {
			min = c;
		}
	}

	std::cout << min << " " << max << std::endl;

	return 0;
}