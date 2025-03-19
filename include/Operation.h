#include <iostream>
#include <vector>
#include "SquareMatrix.h"

class Operation {

public:
	Operation();
	
	virtual SquareMatrix aplly(const std::vector<SquareMatrix>& mat) const = 0;

private:
	std::vector<std::shared_ptr<Operation>> operations;

};