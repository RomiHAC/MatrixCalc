#include "OperationManager.h"

// Add a new operation with a name and return its index
int OperationManager::addOperation(std::shared_ptr<Operation> op, const std::string& name) {
    int index = operations.size();
    operations.push_back(op);
    operationNames[index] = name; // Store the name
    return index;
}

// Execute an operation by its index
SquareMatrix OperationManager::execute(int index, const std::vector<SquareMatrix>& matrices) {
    if (index < 0 || index >= static_cast<int>(operations.size())) {
        throw std::out_of_range("Invalid operation index.");
    }
    std::cout << std::endl << operationNames.at(index) << "(\n";// Print operation name
    matrices[0].printMatrix();
    std::cout << ") =\n"; 
    return operations[index]->apply(matrices);
}

// Print the list of available operations
void OperationManager::listOperations() const {
    std::cout << "List of available matrix operations:\n";
    for (size_t i = 0; i < operations.size(); ++i) {
        std::cout << i << ". " << operationNames.at(i) << std::endl;
    }
    std::cout << std::endl;
}
