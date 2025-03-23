#include "CompOperation.h"

CompOperation::CompOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2)
    : op1(op1), op2(op2) {
}

SquareMatrix CompOperation::apply(const std::vector<SquareMatrix>& matrices) const {
    if (matrices.empty()) {
        throw std::invalid_argument("Error: No matrices provided for CompOperation.");
    }

    // Apply the first operation
    SquareMatrix mat_op1 = op1->apply(matrices);

    // Pass the result of op1 into op2
    std::vector<SquareMatrix> mat_op2 = { mat_op1 };  // Corrected syntax
    SquareMatrix result = op2->apply(mat_op2);

    return result;
}

int CompOperation::getNumMatrices() const {
    return op1->getNumMatrices();  // Ensure correct matrix count
}
