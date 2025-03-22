#pragma once
#include <iostream>
#include <vector>

class SquareMatrix {
public:

    SquareMatrix(int n);
    SquareMatrix(const std::vector<std::vector<int>>& mat);

   
    const std::vector<std::vector<int>>& getMatrix() const; // for constant access
    std::vector<std::vector<int>>& getMatrix(); // for non-constant access

    void printMatrix() const;

private:
    int size;
    std::vector<std::vector<int>> matrix;
};

