#pragma once
#include "SquareMatrix.h"
#include <vector>
#include <memory>
#include <iostream>

class Operation {
public:
    Operation();
    virtual ~Operation() = default;

    virtual SquareMatrix apply(const std::vector<SquareMatrix>& mat) const = 0;
};
