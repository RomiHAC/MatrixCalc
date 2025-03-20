#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include <iostream>
#include "Operation.h"
#include "SquareMatrix.h"

class OperationManager {
private:
    std::vector<std::shared_ptr<Operation>> operations;  // Stores operations
    std::unordered_map<int, std::string> operationNames; // Maps index to operation name

public:
    // Adds a new operation with a name and returns its index
    int addOperation(std::shared_ptr<Operation> op, const std::string& name);

    // Executes an operation by index, passing the required matrices
    SquareMatrix execute(int index, const std::vector<SquareMatrix>& matrices);

    // Prints the list of available operations
    void listOperations() const;
};
