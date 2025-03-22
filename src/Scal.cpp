#include "Scal.h"

Scal::Scal(int scalar) : scalar(scalar) {}

SquareMatrix Scal::apply(const std::vector<SquareMatrix>& mat) const {
    return mat[0] * scalar;
}

int Scal::getNumMatrices() const {
    return 1;
}
