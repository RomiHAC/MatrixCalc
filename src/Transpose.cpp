#include "Transpose.h"

SquareMatrix Transpose::apply(const std::vector<SquareMatrix>& mat) const {
    int n = mat[0].getMatrix().size();
    std::vector<std::vector<int>> transposed(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transposed[j][i] = mat[0].getMatrix()[i][j];
        }
    }

    return SquareMatrix(transposed);  // Return the new transposed matrix
}
