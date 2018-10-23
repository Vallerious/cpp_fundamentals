#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <math.h>

class Quadratic {
public:
	Quadratic(double a, double b, double c) : a(a), b(b), c(c) {
		this->discriminant = this->calculateDiscriminant();
		this->positiveQuadratic = this->calculatePositiveQuadraticEquasion();
		this->negativeQuadratic = this->calculateNegativeQuadraticEquasion();
	}

	double getDiscriminant() const {
		return this->discriminant;
	}

	double getPositiveQuadraticValue() const {
		return this->positiveQuadratic;
	}

	double getNegativeQuadraticValue() const {
		return this->negativeQuadratic;
	}

	double hasNoRoots() const {
		return this->discriminant < 0;
	}

	double hasOneRoot() const {
		return this->discriminant == 0;
	}

	double hasTwoRoots() const {
		return this->discriminant > 0;
	}

private:
	double a;
	double b;
	double c;
	double discriminant;
	double positiveQuadratic;
	double negativeQuadratic;

	double calculateDiscriminant() const {
		return (this->b * this->b) - (4 * this->a * this->c);
	}

	double calculatePositiveQuadraticEquasion() const {
		return (-this->b + sqrt(this->discriminant)) / (2 * this->a);
	}

	double calculateNegativeQuadraticEquasion() const {
		return (-this->b - sqrt(this->discriminant)) / (2 * this->a);
	}
};

#endif