#include <vector>
#include <iostream>
#include <string>
#include <sstream>

std::vector<std::vector<int> > readMatrix() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int> > matrix;

	std::string matrixRowLine;
	getline(std::cin, matrixRowLine); // consume the text line
	for (size_t i = 0; i < n; i++) {
		getline(std::cin, matrixRowLine);
		std::istringstream matrixRowLineIn(matrixRowLine);
		std::vector<int> columnMatrix;
		int c;

		while (matrixRowLineIn >> c) {
			columnMatrix.push_back(c);
		}

		matrix.push_back(columnMatrix);
	}

	return matrix;
}

bool compareMatrices(const std::vector<std::vector<int> >& m1, const std::vector<std::vector<int> >& m2) {
	if (m1.size() != m2.size()) return false;

	for (size_t row = 0; row < m1.size(); row++) {
		if (m1[row].size() != m2[row].size()) {
			return false;
		}

		for (size_t col = 0; col < m1[row].size(); col++) {
			if (m1[row][col] != m2[row][col]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	std::vector<std::vector<int> > matrix1 = readMatrix();
	std::vector<std::vector<int> > matrix2 = readMatrix();

	bool areEqual = compareMatrices(matrix1, matrix2);

	std::cout << (areEqual ? "equal" : "not equal") << std::endl;

	return 0;
}