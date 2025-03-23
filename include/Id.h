#pragma once
#include "Operation.h"

class Id : public Operation {
public:
    SquareMatrix apply(const std::vector<SquareMatrix>& mat) const override;  
    int getNumMatrices() const override;
};
