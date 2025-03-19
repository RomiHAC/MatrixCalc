#include "Help.h"

void Help::Expl(){
	std::cout << "The available commands are: /n"
		"* eval(uate) num n - compute the result of operation #num on all"
		"needed n×n matrices(that will be prompted) /n"
		"* scal(ar) val - creates an operation that multiplies the given"
		"matrix by scalar val /n"
		"* add num1 num2 - creates an operation that is the addition of the"
		"result of operation #num1 and the result of operation #num2 /n"
		"* sub num1 num2 - creates an operation that is the subtraction of the"
		"result of operation #num1 and the result of operation #num2 /n"
		"* comp(osite) num1 num2 - creates an operation that is the"
		"composition of operation #num1 and operation #num2 /n"
		"* del(ete) num - delete operation #num from the operation list /n"
		"* help - print this command list /n"
		"* exit - exit the program ";

}