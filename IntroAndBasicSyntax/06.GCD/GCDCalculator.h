#ifndef GCD_CALCULATOR_H
#define GCD_CALCULATOR_H

class GCDCalculator {
public:
	GCDCalculator(int a, int b): a(a), b(b) {}

	int calculate() const {
		int gcd = 0, left = 0, right = 0, remainder;
		int aTemp = this->a;
		int bTemp = this->b;

		do {
			if (aTemp > bTemp) {
				left = aTemp;
				right = bTemp;
			}
			else {
				left = bTemp;
				right = aTemp;
			}

			int divisionResult = left / right;
			remainder = left % right;

			aTemp = right;
			bTemp = remainder;
		} while (remainder != 0);

		return right;
	}
private:
	int a;
	int b;
};

#endif