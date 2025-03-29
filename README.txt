Square matrices calculator
program by: Or-Ram Atar(325004851) and Romi Sinizkey (322311457)

This project is a Matrix Calculator implemented in C++. It provides various matrix operations,
such as addition, subtraction, multiplication, and transposition. 
The program allows users to input matrices and perform calculations 
through a simple text-based interface. 
the user can create new functions such as add 2 result from other 2 function,
subtract, transpose and adding a scale with a desired number 

files in the project:
Operation.h, Operation.cpp abstract class contained "apply" virtual function that gets a vector of metrics, and returns a single metrics
as well as "getNumMatrices" virtual function that returns int will use to get the number of needed metrics for the operation for every class that inherit has a different number of required metrics
AddOperation.h, AddOperation.cpp: inherit from Operation class, constructor initialize 2 shared ptr operations and the apply function adds the 2 result from the operations and return the result   
CompOperation.h, CompOperation.cpp: inherit from Operation class, constructor initialize 2 shared ptr operations and the apply function compose the first result from the first operation and send it to the second operation then return the result   
Help.h, Help.cpp: has one function to print the help text
Id.h, Id.cpp: inherit from Operation class, apply function returns the same matrices
Scal.h, Scal.cpp: inherit from Operation class, constructor initialize an int number and the apply function multiply the metrics by that same int
SubOperation.h, SubOperation.cpp: inherit from Operation class, constructor initialize 2 shared ptr operations and the apply function subtract the 2 result from the operations and return the result   
Transpose.h, Transpose.cpp: inherit from Operation class, the apply function switch the columns and rows and return the result
OperationManager.h, OperationManager.cpp: in charge of handling the functions in the calculater, calls the operations, adding new functions to the calculator, deleting desired functions, list the exist functions...
SquareMatrix.h, SquareMatrix.cpp: class to represent a metrics, has getMetrix function, create metrix function, and overload operators of the following: +, -, *(int), *(metrix), <<, >>.

    
Main Data Structures:
std::vector<std::shared_ptr<Operation>> : holds the existing functions.
std::unordered_map<int, std::string> : Stores the name of the operation in the same index.

Special Algorithms:

Design Overview:
the operarion manager controls the calculator, it is in charge of adding deleting and more to the calculator, every other operation in charge of excute the operation they need to do.

notes: 

