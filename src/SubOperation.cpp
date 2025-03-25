#include "SubOperation.h"

SubOperation::SubOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2)
    : op1(op1), op2(op2) {
}

SquareMatrix SubOperation::apply(const std::vector<SquareMatrix>& matrices) const {
    if (matrices.size() < getNumMatrices()) {
        throw std::invalid_argument("Error: SubOperation requires at least " + std::to_string(getNumMatrices()) + " matrices.");
    }

    int numOp1 = op1->getNumMatrices();
    int numOp2 = op2->getNumMatrices();

    std::vector<SquareMatrix> matricesForOp1(matrices.begin(), matrices.begin() + numOp1);
    std::vector<SquareMatrix> matricesForOp2(matrices.begin() + numOp1, matrices.begin() + numOp1 + numOp2);

    SquareMatrix mat_op1 = op1->apply(matricesForOp1);
    SquareMatrix mat_op2 = op2->apply(matricesForOp2);

    return mat_op1 - mat_op2;
}

int SubOperation::getNumMatrices() const {
    return op1->getNumMatrices() + op2->getNumMatrices();
}

