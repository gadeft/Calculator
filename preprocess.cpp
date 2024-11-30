#define PATTERN "0123456789+-*/^()."

std::string preprocess(std::string input_row)
{
	int size = input_row.size();
	for (int i = 0; i < size; i++)
	{
		int pos = input_row.find_first_not_of(PATTERN);
		if (pos == std::string::npos)
			return input_row;
		input_row.erase(pos, 1);
	}
	return input_row;
}
