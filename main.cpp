#include <iostream>
#include <string>
#include <cmath>

#include "reverse_notation.cpp"
#include "preprocess.cpp"
#include "compiler.cpp"

int main()
{
	std::string row;
	std::cout << "Enter a row: " << std::endl;
	getline(std::cin, row);
//deletes extra characters
	row = preprocess(row);
//changes the expression in reverse polak notation
	row = reverse_notation(row);
//calculates the expression
	row = compiler(row);
	std::cout << "The result is " << row << std::endl;
}
