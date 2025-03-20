#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(int n)
    : size(n), matrix(n, std::vector<int>(n, 0)) {
    std::cout << "\nEnter " << n << "x" << n << " values for the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

SquareMatrix::SquareMatrix(const std::vector<std::vector<int>>& mat)
    : size(mat.size()), matrix(mat) {
}

std::vector<std::vector<int>> SquareMatrix::getMatrix() const {
    return matrix;
}

void SquareMatrix::printMatrix() const {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
