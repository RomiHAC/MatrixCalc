#include "AddOperation.h"

AddOperation::AddOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2)
    : op1(op1), op2(op2) {
}

SquareMatrix AddOperation::apply(const std::vector<SquareMatrix>& matrices) const {
    if (matrices.size() < 2) {
        throw std::invalid_argument("Error: AddOperation requires at least two matrices.");
    }

    // Apply the first operation (op1)
    SquareMatrix mat_op1 = op1->apply(matrices);

    // Apply the second operation (op2)
    SquareMatrix mat_op2 = op2->apply(matrices);

    // Add the results
    return mat_op1 + mat_op2;
}

int AddOperation::getNumMatrices() const {
    // This method should return the correct number of matrices based on the operations.
    // Assuming `op1` and `op2` each need one matrix.
    int numMatricesOp1 = op1->getNumMatrices();
    int numMatricesOp2 = op2->getNumMatrices();

    return std::max(numMatricesOp1, numMatricesOp2);  // Adjust based on how you want to count matrices.
}
