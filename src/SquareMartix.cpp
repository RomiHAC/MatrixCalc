#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(int n) 
	: size(n), matrix(n, std::vector<int>(n,0)) {

    std::cout << "Enter " << n * n << " values for the matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j]; 
            std::cout << matrix[i][i] <<" ";
        }
        std::cout << " /n";
    }
}



