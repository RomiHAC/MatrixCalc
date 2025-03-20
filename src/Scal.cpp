#include "Scal.h"

// Constructor to initialize the scalar value
Scal::Scal(int scalar) : scalar(scalar) {}

// Implement the apply method for scalar multiplication
SquareMatrix Scal::apply(const std::vector<SquareMatrix>& mat) const {


    int n = mat[0].getMatrix().size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
           result[i][j] = mat[0].getMatrix()[i][j] * scalar;
        }
    }
    return result;
}
