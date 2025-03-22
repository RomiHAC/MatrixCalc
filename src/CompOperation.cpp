#include "CompOperation.h"

CompOperation::CompOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2)
	:op1(op1), op2(op2) {}

SquareMatrix CompOperation::apply(const std::vector<SquareMatrix>& matrices) const
{
   
    // Apply op1 and op2 to get the resulting matrices
    SquareMatrix mat_op1 = op1->apply(matrices);  // Fixed typo from aplly -> apply
    const std::vector<SquareMatrix>& mat_op2 = { mat_op1 };
    SquareMatrix result = op2->apply(mat_op2);  // Fixed typo from aplly -> apply

    // Return the resulting matrix after addition
    return result;
}

