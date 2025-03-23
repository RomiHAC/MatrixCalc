#pragma once
#include "Operation.h"


class SubOperation : public Operation {

public:
	SubOperation(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2);
	SquareMatrix apply(const std::vector<SquareMatrix>& matrices) const override;
	int getNumMatrices() const override;
private:
	std::shared_ptr<Operation> op1;
	std::shared_ptr<Operation> op2;
};
