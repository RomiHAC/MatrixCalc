#include "Operation.h" 
#include "OperationManager.h" 
#include "string"


int main(){
	std::string command;
	OperationManager manager;


	while (true) {
        manager.listOperations();
        std::cout << "Enter command ('help' for list of available commands) :";
        std::cin >> command;

		if (command == "help") {
            manager.getHelp().printHelp();
		}

		else if (command == "exit") {
			std::cout << "\nGoodbye!\n";
			break;
		}
        else if (command == "eval") {
            int index, size;
            std::cin >> index >> size;

            // Check if index is within valid range
            if (index < 0 || index >= manager.getOperationsCount()) {
                std::cout << "Invalid index! Please enter a valid operation index.\n";
                continue;  
            }

            int requiredMatrices = manager.getRequiredMatrixCount(index);

            std::vector<SquareMatrix> matrices;
            if (requiredMatrices > 1)
                std::cout << "\nplease enter " << requiredMatrices << " matrices:" << std::endl;
            for (int i = 0; i < requiredMatrices; ++i) {
                SquareMatrix matrix(size);
                matrix.createMatrix();
                matrices.push_back(matrix);
            }

            SquareMatrix result = manager.execute(index, matrices);
            std::cout << result << std::endl;
        }

        else if (manager.CheckOptAndAdd(command)) {
           // Pass the command 
        }

        else {
            std::cout << "Unknown command. Type 'help' for a list of commands.\n";
        }
     }

}


