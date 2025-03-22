#pragma once
#include "Operation.h"

class CompOperation :public  Operation {
public:
    
	CompOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2);

	SquareMatrix apply(const std::vector<SquareMatrix>& matrices) const override;

private:
	std::shared_ptr<Operation> op1;
	std::shared_ptr<Operation> op2;
};