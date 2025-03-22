#pragma once
#include "Operation.h"

class Scal : public Operation {
public:
    // Constructor to initialize the scalar value
    Scal(const int scalar);

    // Override the apply method to perform scalar multiplication
    SquareMatrix apply(const std::vector<SquareMatrix>& matrices) const override;
private:
    int scalar;  // Scalar value for multiplication

};
