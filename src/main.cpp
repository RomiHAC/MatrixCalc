#include "Operation.h" 
#include "OperationManager.h" 
#include "SquareMatrix.h"
#include "Id.h"
#include "Transpose.h"
#include "Scal.h"
#include "string"

void printHelp();
int main(){
	std::string command;
	OperationManager manager;
	manager.addOperation(std::make_shared<Id>(), "id");
	manager.addOperation(std::make_shared<Transpose>(), "tran");

	while (true) {
        manager.listOperations();
		std::cout << "Enter command ('help' for list of available commands) :";
		std::cin >> command;
         
		if (command == "help") {
            printHelp();
		}

		else if (command == "exit") {
			std::cout << "Goodbye!/n";
			break;
		}
        else if (command == "eval") {
            int index, size;
            std::cin >> index >> size;

            SquareMatrix matrix(size);
            std::vector<SquareMatrix> matrices = { matrix };
            // Execute the operation and print result
            SquareMatrix result = manager.execute(index, matrices);
            result.printMatrix(); // Assuming SquareMatrix has a print() function
			std::cout << std::endl;

        }
        else if (command == "scal") {
            int val;
            std::cin >> val;
            // Create a new Scal operation with the given scalar value
            manager.addOperation(std::make_shared<Scal>(val), "Scal " + std::to_string(val)); // Pass val to Scal
        }

        else {
            std::cout << "Unknown command. Type 'help' for a list of commands.\n";
        }
	}

}


void printHelp() {
    std::cout << "\n1. eval(num, n) - Calculates the function for 'num' index using an 'nXn' matrix from the user." << std::endl;
    std::cout << "2. scal(val) - Multiplies the matrix from 'eval' by the scalar 'val'." << std::endl;
    std::cout << "3. add(num1, num2) - Adds the results of functions 'num1' and 'num2' (element-wise)." << std::endl;
    std::cout << "4. sub(num1, num2) - Subtracts function 'num2' from 'num1' (element-wise)." << std::endl;
    std::cout << "5. comp(num1, num2) - Applies function 'num1' first, then 'num2' on the result." << std::endl;
    std::cout << "6. del(num) - Deletes function 'num' and updates the list." << std::endl;
    std::cout << "7. help - Displays a list of commands with brief descriptions." << std::endl;
    std::cout << "8. exit - Prints 'Goodbye' and exits the program." << std::endl;
    std::cout << std::endl;
}
