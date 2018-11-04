#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template<typename T>
std::vector<std::vector<T> > readMatrixKnownSize() {
	int rowsCount, colsCount;
	std::cin >> rowsCount >> colsCount;

	std::string matrixLine;
	getline(std::cin, matrixLine);
	std::vector<std::vector<T> > matrix;

	for (size_t i = 0; i < rowsCount; i++) {
		getline(std::cin, matrixLine);

		std::istringstream matrixLineIn(matrixLine);
		T c;
		std::vector<T> innerMatrix;

		while (matrixLineIn >> c) {
			innerMatrix.push_back(c);
		}

		matrix.push_back(innerMatrix);
	}

	return matrix;
}

template<typename T>
void printMatrix(std::vector<std::vector<T> > matrix) {
	for (std::vector<T> inner : matrix) {
		for (T smth : inner) {
			std::cout << smth << "";
		}

		std::cout << std::endl;
	}
}

void fillMatrix(vector<vector<char> >& matrix, int startRow, int startCol, char targetChar, char fill) {
	if (startRow < 0 || startCol < 0 || startRow > matrix.size() - 1 ||
		(matrix.size() > 0 && startCol > matrix[0].size() - 1) || matrix[startRow][startCol] != targetChar) {
		return;
	}

	matrix[startRow][startCol] = fill;

	fillMatrix(matrix, startRow - 1, startCol, targetChar, fill);
	fillMatrix(matrix, startRow, startCol + 1, targetChar, fill);
	fillMatrix(matrix, startRow + 1, startCol, targetChar, fill);
	fillMatrix(matrix, startRow, startCol - 1, targetChar, fill);
}

int main() {
	vector<vector<char> > matrix = readMatrixKnownSize<char>();
	char fill;
	int startRow, startCol;
	cin >> fill >> startRow >> startCol;

	fillMatrix(matrix, startRow, startCol, matrix[startRow][startCol], fill);

	printMatrix(matrix);

	return 0;
}