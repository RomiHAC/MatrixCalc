#pragma once
#include <iostream>
#include <vector>

class SquareMatrix {
public:

    SquareMatrix(int n);
    SquareMatrix(const std::vector<std::vector<int>>& mat);
    const std::vector<std::vector<int>>& getMatrix() const; // for constant access
    void setMatrix(const std::vector<std::vector<int>>& newMatrix);
    void createMatrix();

 //   std::vector<std::vector<int>> getMatrix() const;
    void printMatrix() const;

    SquareMatrix operator+(const SquareMatrix& other) const;
    SquareMatrix operator-(const SquareMatrix& other) const;
    SquareMatrix operator*(const SquareMatrix& other) const;
    SquareMatrix operator*(int scalar) const;
    bool operator==(const SquareMatrix& other) const;

    friend std::ostream& operator<<(std::ostream& out, const SquareMatrix& matrix);
    friend std::istream& operator>>(std::istream& in, SquareMatrix& matrix);

private:
    int size;
    std::vector<std::vector<int>> matrix;
};