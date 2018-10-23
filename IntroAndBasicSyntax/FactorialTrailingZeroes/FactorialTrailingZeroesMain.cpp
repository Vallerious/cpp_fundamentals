#include <iostream>

namespace FactorialTrailingZeroes {
	int findTrailingZeros(int n)
	{
		// Initialize result 
		int count = 0;

		// Keep dividing n by powers of  
		// 5 and update count 
		for (int i = 5; n / i >= 1; i *= 5)
			count += n / i;

		return count;
	}
}

int main() {
	int n;

	std::cin >> n;

	std::cout << FactorialTrailingZeroes::findTrailingZeros(n) << std::endl;

	return 0;
}
