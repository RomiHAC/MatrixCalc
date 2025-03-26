#include "Help.h"

void Help::printHelp() const {
    std::cout << "\nThe available commands are :\n";
    std::cout << "*eval(uate) num n - compute the result of operation #num on all\nneeded nxn matrices(that will be prompted)\n";
    std::cout << "* scal(ar) val - creates an operation that multiplies the given\nmatrix by scalar val\n";
    std::cout << "* add num1 num2 - creates an operation that is the addition of the\nresult of operation #num1 and the result of operation #num2\n";
    std::cout << "* sub num1 num2 - creates an operation that is the subtraction of the\n result of operation #num1 and the result of operation #num2\n";
    std::cout << "* comp(osite) num1 num2 - creates an operation that is the\ncomposition of operation #num1 and operation #num2\n";
    std::cout << "* del(ete) num - delete operation #num from the operation list\n";
    std::cout << "* help - print this command list\n";
    std::cout << "* exit - exit the program\n";
    std::cout << std::endl;
}
