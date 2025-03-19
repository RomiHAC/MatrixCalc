#pragma once
#include <iostream>
#include <vector>



class SquareMatrix {

public:
	SquareMatrix(int n);
	

private:
	int size;
	std::vector<std::vector<int>> matrix;
	

};