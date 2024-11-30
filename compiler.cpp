#define OPERATIONS "+-*/^"

std::string calculation(double, double, char);

std::string compiler(std::string input_row)
{
	if (input_row.find_first_of(OPERATIONS, 1) == std::string::npos) //recursion exit condition
		return input_row;

	//gets the posions of the separators (space)
	int pos[3];
	pos[0] = input_row.find_first_of(OPERATIONS); //searches for operator
	while (( input_row[pos[0] + 1] != ' ' ) and ( pos[0] != input_row.size() - 1)) //eliminates the choice of unary minus
	{
		pos[0] = input_row.find_first_of(OPERATIONS, pos[0] + 1);
	}
	pos[1] = input_row.find_last_of(" ", pos[0] - 2);
	pos[2] = input_row.find_last_of(" ", pos[1] - 1);
	
	char operation = input_row[pos[0]];
	double first_operand = std::stod(input_row.substr(pos[2] + 1, pos[1] - pos[2] - 1));
	double second_operand = std::stod(input_row.substr(pos[1] + 1, pos[0] - pos[1] - 1));

	std::string result = calculation(first_operand, second_operand, operation);

	input_row.erase(pos[2] + 1, pos[0] - pos[2]);
	input_row.insert(pos[2] + 1, result);

	return compiler(input_row);
}

std::string calculation(double first_operand, double second_operand, char operation)
{
	switch(operation)
	{
		case '+':
			return std::to_string(first_operand + second_operand);
		case '-':
			return std::to_string(first_operand - second_operand);
		case '*':
			return std::to_string(first_operand * second_operand);
		case '/':
			return std::to_string(first_operand / second_operand);
		case '^':
			return std::to_string(pow(first_operand, second_operand));
	}
	return "error";
}
