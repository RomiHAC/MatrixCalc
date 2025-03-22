#pragma once
#include <unordered_map>
#include "Operation.h"
#include "Id.h"
#include "Transpose.h"
#include "Scal.h"
#include "Help.h"
#include "AddOperation.h"
#include "SubOperation.h"
#include "CompOperation.h"

class OperationManager {
private:
    std::vector<std::shared_ptr<Operation>> operations;  // Stores operations
    std::unordered_map<int, std::string> operationNames; // Maps index to operation name
    std::vector<int> requiredMatrices;
    Help help;

public:

    OperationManager();


     const Help& getHelp()  ;

    // Adds a new operation with a name and returns its index
    int addOperation(std::shared_ptr<Operation> op, const std::string& name);

    void DeleteFunction(const int num);

    // Executes an operation by index, passing the required matrices
    SquareMatrix execute(int index, const std::vector<SquareMatrix>& matrices);

    // Prints the list of available operations
    void listOperations() const;

    bool OperationExists(const std::string& name) const;

    bool CheckOptAndAdd(const std::string& command);

    int getRequiredMatrixCount(int index);

    

    
};
