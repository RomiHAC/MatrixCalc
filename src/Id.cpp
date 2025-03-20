#include "Id.h"

SquareMatrix Id::apply(const std::vector<SquareMatrix>& mat) const {

    return mat[0];  // Identity function just returns the same matrix
}
