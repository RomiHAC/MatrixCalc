#pragma once
#include "Operation.h"

class Scal : public Operation {
public:
    Scal(int scalar);
    SquareMatrix apply(const std::vector<SquareMatrix>& matrices) const override;
    int getNumMatrices() const override;
private:
    int scalar;
};
