#include "SquareMatrix.h"


SquareMatrix::SquareMatrix(int n)
    : size(n), matrix(n, std::vector<int>(n, 0)) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

void SquareMatrix::createMatrix() { 
    std::cout << "\nEnter " << size << "x" << size << " values for the matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

SquareMatrix::SquareMatrix(const std::vector<std::vector<int>>& mat)
    : size(mat.size()), matrix(mat) {
}

//std::vector<std::vector<int>> SquareMatrix::getMatrix() const {
//    return matrix;
//}

const std::vector<std::vector<int>>& SquareMatrix::getMatrix() const {
    return matrix;  
}

void SquareMatrix::setMatrix(const std::vector<std::vector<int>>& newMatrix) {
    if (newMatrix.size() != size) {
        throw std::invalid_argument("Matrix size mismatch.");
    }
    matrix = newMatrix;
}

void SquareMatrix::printMatrix() const {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

SquareMatrix SquareMatrix::operator+(const SquareMatrix& other) const {
    if (size != other.size) throw std::invalid_argument("Matrix sizes must be equal for addition.");

    SquareMatrix result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];

    return result;
}

SquareMatrix SquareMatrix::operator-(const SquareMatrix& other) const {
    if (size != other.size) throw std::invalid_argument("Matrix sizes must be equal for subtraction.");

    SquareMatrix result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];

    return result;
}

SquareMatrix SquareMatrix::operator*(const SquareMatrix& other) const {
    if (size != other.size) throw std::invalid_argument("Matrix sizes must be equal for multiplication.");

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

bool SquareMatrix::operator==(const SquareMatrix& other) const {
    return matrix == other.matrix;
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
