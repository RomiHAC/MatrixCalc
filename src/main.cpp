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
			std::cout << "Goodbye!/n";
			break;
		}
        else if (command == "eval") {
            int index, size;
            std::cin >> index >> size;

            int requiredMatrices = manager.getRequiredMatrixCount(index); 

            std::vector<SquareMatrix> matrices;
            std::cout << "please write " << requiredMatrices << " matrix" << std::endl;
            for (int i = 0; i < requiredMatrices; ++i) {
                SquareMatrix matrix(size);
                matrices.push_back(matrix);
            }

            // Execute the operation and print result
            SquareMatrix result = manager.execute(index, matrices);
            result.printMatrix();
            std::cout << std::endl;
        }

       
        else if (manager.CheckOptAndAdd(command)) {
           // Pass the command 
        }

        else {
            std::cout << "Unknown command. Type 'help' for a list of commands.\n";
        }
     }

}


