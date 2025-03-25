#include "CompOperation.h"

CompOperation::CompOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2)
    : op1(op1), op2(op2) {
}


SquareMatrix CompOperation::apply(const std::vector<SquareMatrix>& matrices) const {
    if (matrices.size() < getNumMatrices()) {
        throw std::invalid_argument("Error: CompOperation requires at least " + std::to_string(getNumMatrices()) + " matrices.");
    }

    int numOp1 = op1->getNumMatrices();

    std::vector<SquareMatrix> matricesForOp1(matrices.begin(), matrices.begin() + numOp1);

    SquareMatrix mat_op1 = op1->apply(matricesForOp1);

    std::vector<SquareMatrix> matricesForOp2;
    matricesForOp2.push_back(mat_op1);  
    matricesForOp2.insert(matricesForOp2.end(), matrices.begin() + numOp1, matrices.end()); 

    SquareMatrix result = op2->apply(matricesForOp2);

    return result;
}




int CompOperation::getNumMatrices() const {
    return std::max(op1->getNumMatrices(), op2->getNumMatrices());
}
