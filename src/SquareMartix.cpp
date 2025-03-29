#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(int n)
    : size(n), matrix(n, std::vector<int>(n, 0)) {
}

void SquareMatrix::createMatrix() {
    std::cout << "\nEnter a " << size << "x" << size << " matrix:\n";
    std::cin >> *this;  
}

SquareMatrix::SquareMatrix(const std::vector<std::vector<int>>& mat)
    : size(mat.size()), matrix(mat) {
}

const std::vector<std::vector<int>>& SquareMatrix::getMatrix() const {
    return matrix;
}

SquareMatrix SquareMatrix::operator+(const SquareMatrix& other) const {

    SquareMatrix result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];

    return result;
}

SquareMatrix SquareMatrix::operator-(const SquareMatrix& other) const {

    SquareMatrix result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];

    return result;
}

SquareMatrix SquareMatrix::operator*(const SquareMatrix& other) const {

    SquareMatrix result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];

    return result;
}

SquareMatrix SquareMatrix::operator*(int scalar) const {
    SquareMatrix result(*this);
    for (auto& row : result.matrix) {
        for (auto& val : row) {
            val *= scalar;
        }
    }
    return result;
}

std::istream& operator>>(std::istream& in, SquareMatrix& matrix) {
    for (int i = 0; i < matrix.size; i++)
        for (int j = 0; j < matrix.size; j++)
            in >> matrix.matrix[i][j];

    return in;
}

std::ostream& operator<<(std::ostream& out, const SquareMatrix& matrix) {
    for (const auto& row : matrix.matrix) {
        for (int val : row)
            out << val << " ";
        out << "\n";
    }
    return out;
}
