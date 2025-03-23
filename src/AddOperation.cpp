#include "AddOperation.h"

AddOperation::AddOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2)
    : op1(op1), op2(op2) {
}

SquareMatrix AddOperation::apply(const std::vector<SquareMatrix>& matrices) const {
    if (matrices.size() < 2) {
        throw std::invalid_argument("Error: AddOperation requires at least two matrices.");
    }

    SquareMatrix mat_op1 = op1->apply(matrices);
    std::vector<SquareMatrix> matricesCopy = matrices;
    matricesCopy[0] = matrices[1];
    SquareMatrix mat_op2 = op2->apply(matricesCopy);

    return mat_op1 + mat_op2;
}


int AddOperation::getNumMatrices() const {
    return 2;
}
