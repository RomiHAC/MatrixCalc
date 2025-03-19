#include "Operation.h" 
#include "SquareMatrix.h"

int main(){
	std::string command;
	Operation opt();
	while (true) {
		std::cout << "List of available matrix operations: /n ";

		//need to prind here the vector of the available commands

		std::cout << "Enter command ('help' for list of available commands) :";
		std::cin >> command;
         
		if (command == "help") {
		   
		}
		else if (command == "exit") {
			std::cout << "Goodbye!/n";
			break;
		}
		else if(command == "eval") {
			
			int index, size;
			std::cin >> index >> size;
			SquareMatrix matrix(size);
			//need to add a funtion so the Operations class would handle based on the index
		
		}
		else  {
		    //need to add other functions like scal..

		}
	}

}
