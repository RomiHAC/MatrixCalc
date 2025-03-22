#include "Help.h"

void Help::printHelp() const {
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