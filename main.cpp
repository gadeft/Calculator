#include <iostream>
#include <string>
#include <cmath>

#include "reverse_notation.cpp"
#include "preprocess.cpp"
#include "funct_lib.cpp"
#include "compiler.cpp"

int main()
{
	std::string row;
	std::cout << "Enter a row: " << std::endl;
	getline(std::cin, row);
	std::cout << "The row                   " << row << std::endl << std::endl;

	row = preprocess(row);
	std::cout << "After prepocessing        " << row << std::endl << std::endl;

	row = reverse_notation(row);
	std::cout << "After reverse notation    " << row << std::endl << std::endl;

	row = compiler(row);
	std::cout << "After compilation         " << row << std::endl << std::endl;
}
