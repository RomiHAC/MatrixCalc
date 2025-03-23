#pragma once
#include "SquareMatrix.h"
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <algorithm>


class Operation {
public:
    Operation() = default;
    virtual ~Operation() = default;
    virtual SquareMatrix apply(const std::vector<SquareMatrix>& mat) const = 0;
    virtual int getNumMatrices() const = 0;
};
