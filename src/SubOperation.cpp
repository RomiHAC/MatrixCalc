#include "SubOperation.h"
#include <iostream>  // For debugging

SubOperation::SubOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2)
    : op1(op1), op2(op2) {
}

SquareMatrix SubOperation::apply(const std::vector<SquareMatrix>& matrices) const {
    if (matrices.size() < getNumMatrices()) {
        throw std::invalid_argument("Error: Not enough matrices provided for SubOperation.");
    }

    std::cout << "Applying first operation:\n";
    SquareMatrix mat_op1 = op1->apply(matrices);
    mat_op1.printMatrix();  // Debug print

    std::cout << "Applying second operation:\n";
    SquareMatrix mat_op2 = op2->apply(matrices);
    mat_op2.printMatrix();  // Debug print

    int size = mat_op1.getMatrix().size();
    SquareMatrix result(size);

    std::vector<std::vector<int>> resultMatrix = result.getMatrix();  // Copy to modify
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            resultMatrix[i][j] = mat_op1.getMatrix()[i][j] - mat_op2.getMatrix()[i][j];
        }
    }
    result.setMatrix(resultMatrix);  // Update matrix values

    std::cout << "Result after subtraction:\n";
    result.printMatrix();  // Debug print
    return result;
}

int SubOperation::getNumMatrices() const {
    return std::max(op1->getNumMatrices(), op2->getNumMatrices());
}
