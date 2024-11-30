void appending(std::string&, std::string&, char);
void stack_to_output(std::string&, std::string&, int);
void brackets_to_output(std::string&, std::string&);
int priority(char symbol);
bool unary_minus_check(std::string&, int);


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
				if (unary_minus_check(input_row, i))
				{
					goto default_case;	
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
				break;
			default:
				default_case:
				output_row.append(1, input_row[i]);
				continue;
		}
	}
	stack_to_output(stack, output_row, 0);
	return output_row;
}

void appending(std::string& stack, std::string& output_row, char symbol)
{
	if (( priority(symbol) <= priority(stack.back()) ) and ( symbol != '(' ))
	{
		output_row.append(" ");
		output_row.append(1, stack.back()); 
		stack.pop_back();
	}
	stack.append(1, symbol);
	if ( symbol != '(' )
		output_row.append(" ");
}

void stack_to_output(std::string& stack, std::string& output_row, int pos)
{
	for (int i = stack.size() - 1; i >= pos; i--)
	{
		output_row.append(" ");
		output_row.append(1, stack[i]);
		stack.pop_back();
	}
	if (pos != 0)
		stack.pop_back();
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

bool unary_minus_check(std::string& input_row, int pos)
{
	if (( pos == 0 ) or ( priority(input_row[pos - 1]) != -1 ) or ( input_row[pos - 1] == '(' ))
		return true;
	return false;
}
