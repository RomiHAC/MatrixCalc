#include "OperationManager.h"

OperationManager::OperationManager() 
{
    addOperation(std::make_shared<Id>(), "id");
    requiredMatrices.push_back(1);
    addOperation(std::make_shared<Transpose>(), "tran");
    requiredMatrices.push_back(1);

}

const Help& OperationManager::getHelp()  
{
    return help;
}

// Add a new operation with a name and return its index
int OperationManager::addOperation(std::shared_ptr<Operation> op, const std::string& name) {
    int index = operations.size();
    operations.push_back(op);
    operationNames[index] = name; // Store the name
    return index;
}


void OperationManager::DeleteFunction(const int num) {
    if (operationNames.find(num) == operationNames.end()) {
        std::cerr << "Error: Function " << num << " does not exist.\n";
        return;
    }

    if (num >= 0 && num < operations.size()) {
        operations.erase(operations.begin() + num);
        requiredMatrices.erase(requiredMatrices.begin() + num);

    }

    std::unordered_map<int, std::string> newOperationNames;
    int newIndex = 0;
    for (size_t oldIndex = 0; oldIndex < operations.size() + 1; ++oldIndex) {
        if (operationNames.find(oldIndex) != operationNames.end()) {
            if (oldIndex != num) {
                newOperationNames[newIndex++] = operationNames[oldIndex];
            }
        }
    }

    operationNames = std::move(newOperationNames);
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




void OperationManager::listOperations() const {
    std::cout << "List of available matrix operations:\n";
    for (size_t i = 0; i < operations.size(); ++i) {
        if (operationNames.find(i) != operationNames.end()) {
            std::cout << i << ". " << operationNames.at(i) << std::endl;
        }
        else {
            std::cout << i << ". [ERROR: Missing name]" << std::endl;
        }
    }
    std::cout << std::endl;
}



bool OperationManager::OperationExists(const std::string& name) const
{
    return std::any_of(operationNames.begin(), operationNames.end(),
        [&](const auto& pair) { return pair.second == name; });
}



bool OperationManager::CheckOptAndAdd(const std::string& command)
{
    std::istringstream iss(command);
    std::string opt;
    iss >> opt;

    if (opt == "id") {
        if (OperationExists("id")) {
            std::cerr << "Error: Operation 'id' already exists.\n";
            return false;
        }
        addOperation(std::make_shared<Id>(), "id");
        requiredMatrices.push_back(1);
    }

    else if (opt == "tran") {
        if (OperationExists("tran")) {
            std::cerr << "Error: Operation 'tran' already exists.\n";
            return false;
        }
        addOperation(std::make_shared<Id>(), "tran");
        requiredMatrices.push_back(1);
    }
    else if (opt == "scal")
    {
        double val;
        std::cin >> val;
       
         std::string opName = "Scal " + std::to_string(val);
         if (OperationExists(opName)) {
             std::cerr << "Error: Operation '" << opName << "' already exists.\n";
              return false;
         }
         addOperation(std::make_shared<Scal>(val), opName);
         requiredMatrices.push_back(1);
        
        return true;
    }
    else if (opt == "add" || opt == "sub" || opt == "comp")
    {
        int num1, num2;
        std::cin >> num1 >> num2;
       
        // Retrieve the operations based on indices num1 and num2
        std::shared_ptr<Operation> op1 = operations[num1];
        std::shared_ptr<Operation> op2 = operations[num2];
        int num_matrices = std::max(requiredMatrices[num1], requiredMatrices[num2]);


        if (opt == "add") {

            std::string opName =  " (" + operationNames.at(num1) + " + " + operationNames.at(num2) + ")";
            if (OperationExists(opName)) {
                std::cerr << "Error: Operation '" << opName << "' already exists.\n";
                return false;
            }
            addOperation(std::make_shared<AddOperation>(op1, op2), opName);
            num_matrices++;
            requiredMatrices.push_back(num_matrices);

        }
        else if (opt == "sub") {
            std::string opName =  " (" + operationNames.at(num1) + " - " + operationNames.at(num2) + ")";
            if (OperationExists(opName)) {
                std::cerr << "Error: Operation '" << opName << "' already exists.\n";
                return false;
            }
            addOperation(std::make_shared<SubOperation>(op1, op2), opName);
            num_matrices++;
            requiredMatrices.push_back(num_matrices);
        }
        else if (opt == "comp") {
            std::string opName =  " (" + operationNames.at(num1) + " -> " + operationNames.at(num2) + ")";
            if (OperationExists(opName)) {
                std::cerr << "Error: Operation '" << opName << "' already exists.\n";
                return false;
            }
            addOperation(std::make_shared<CompOperation>(op1, op2), opName);
            requiredMatrices.push_back(num_matrices);

        }
        
        return true;
    }
    else if (opt == "del")
    {
        int num;
        std::cin >> num;
        
            if (operationNames.find(num) == operationNames.end()) {
                std::cerr << "Error: Function does not exist.\n";
                return false;
            }

            DeleteFunction(num);
        
        return true;
    }
    return false;
}


int OperationManager::getRequiredMatrixCount(int index) {
    if (index < 0 || index >= static_cast<int>(operations.size())) {
        throw std::out_of_range("Invalid operation index.");
    }
    return requiredMatrices[index];
}

