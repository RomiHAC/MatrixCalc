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
public:

    OperationManager();

    int getOperationsCount() const;
     const Help& getHelp()  ;
    int addOperation(std::shared_ptr<Operation> op, const std::string& name);
    void DeleteFunction(const int num);
    SquareMatrix execute(int index, const std::vector<SquareMatrix>& matrices);
    void listOperations() const;
    bool OperationExists(const std::string& name) const;
    bool CheckOptAndAdd(const std::string& command);
    int getRequiredMatrixCount(int index);
    
private:
    std::vector<std::shared_ptr<Operation>> operations;  // Stores operations
    std::unordered_map<int, std::string> operationNames; // Maps index to operation name
    std::vector<int> requiredMatrices;
    Help help;

};
