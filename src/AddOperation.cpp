#include "AddOperation.h"

AddOperation::AddOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2)
 : op1(op1), op2(op2){}

SquareMatrix AddOperation::apply(const std::vector<SquareMatrix>& matrices) const {
    SquareMatrix mat_op1 = op1->apply(matrices);
    SquareMatrix mat_op2 = op2->apply(matrices);

    int size = mat_op1.getMatrix().size();
    SquareMatrix result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.getMatrix()[i][j] = mat_op1.getMatrix()[i][j] + mat_op2.getMatrix()[i][j];
        }
    }
    return result;
}


