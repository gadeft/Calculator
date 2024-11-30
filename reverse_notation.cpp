void appending(std::string&, std::string&, char);
void stack_to_output(std::string&, std::string&, int);
int priority(char symbol);


std::string reverse_notation(std::string input_row)
{
	std::string output_row;
	std::string stack;

	for (int i = 0; i < input_row.size(); i++)
	{
		switch(input_row[i])
		{
			case '+':
				appending(stack, output_row, '+');
				break;
			case '-':
				if (( i == 0 ) or ( priority(input_row[i - 1]) != -1 ) or ( input_row[i - 1] == '(' )) //checks minus for unary
				{
					output_row.append(1, input_row[i]); //appends the minus as a number
					break;
				}
				appending(stack, output_row, '-');
				break;
			case '*':
				appending(stack, output_row, '*');
				break;
			case '/':
				appending(stack, output_row, '/');
				break;
			case '^':
				appending(stack, output_row, '^');
				break;
			case '(':
				appending(stack, output_row, '(');
				break;
			case ')':
				stack_to_output(stack, output_row, stack.find_last_of('(') + 1);
				stack.pop_back();
				break;
			default:
				output_row.append(1, input_row[i]);
				continue;
		}
	}
	stack_to_output(stack, output_row, 0);
	return output_row;
}

void appending(std::string& stack, std::string& output_row, char symbol)
{
	//pulls out the last symbol in stack to output
	if (( priority(symbol) <= priority(stack.back()) ) and ( symbol != '(' ))
	{
		output_row.append(" "); //adds the separator which is needed to separate number from operations
		output_row.append(1, stack.back()); 
		stack.pop_back();
	}

	stack.append(1, symbol);
	if ( symbol != '(' )
		output_row.append(" "); //adds the separator which is needed to separate number from operations
}

void stack_to_output(std::string& stack, std::string& output_row, int pos)
{
	for (int i = stack.size() - 1; i >= pos; i--)
	{
		output_row.append(" "); //adds the separator which is needed to separate number from operations
		output_row.append(1, stack[i]);
		stack.pop_back();
	}
}

int priority(char symbol)
{
	switch(symbol)
	{
		case '+':
			return 0;
		case '-':
			return 0;
		case '*':
			return 1;
		case '/':
			return 1;
		case '^':
			return 2;
		default:
			return -1;
	}
}
