#pragma once
#include <iostream>
#include <vector>

class SquareMatrix {
public:

    SquareMatrix(int n);
    SquareMatrix(const std::vector<std::vector<int>>& mat);

    std::vector<std::vector<int>> getMatrix() const;

    void printMatrix() const;

private:
    int size;
    std::vector<std::vector<int>> matrix;
};

