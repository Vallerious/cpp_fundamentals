#include <vector>
#include <iostream>
#include <string>
#include <sstream>

std::vector<std::vector<int> > readMatrixKnownSize() {
	int rowsCount, colsCount;
	std::cin >> rowsCount >> colsCount;

	std::string matrixLine;
	getline(std::cin, matrixLine);
	std::vector<std::vector<int> > matrix;

	for (size_t i = 0; i < rowsCount; i++) {
		getline(std::cin, matrixLine);

		std::istringstream matrixLineIn(matrixLine);
		int c;
		std::vector<int> innerMatrix;

		while (matrixLineIn >> c) {
			innerMatrix.push_back(c);
		}

		matrix.push_back(innerMatrix);
	}
	
	return matrix;
}

std::vector<std::vector<size_t> > findIndexesInMatrix(const std::vector<std::vector<int> >& matrix, int needle) {
	std::vector<std::vector<size_t> > foundIndexes;

	for (size_t row = 0; row < matrix.size(); row++) {
		for (size_t col = 0; col < matrix[row].size(); col++) {
			if (matrix[row][col] == needle) {
				std::vector<size_t> foundIndex = {row, col};
				foundIndexes.push_back(foundIndex);
			}
		}
	}

	return foundIndexes;
}

template<typename T>
void printMatrix(std::vector<std::vector<T> > matrix) {
	for (std::vector<T> inner : matrix) {
		for (T smth : inner) {
			std::cout << smth << " ";
		}

		std::cout << std::endl;
	}
}

int main() {
	std::vector<std::vector<int> > matrix = readMatrixKnownSize();

	int needle;
	std::cin >> needle;

	auto foundIdxs = findIndexesInMatrix(matrix, needle);

	if (foundIdxs.empty()) {
		std::cout << "not found" << std::endl;
		return 0;
	}

	printMatrix(foundIdxs);

	return 0;
}