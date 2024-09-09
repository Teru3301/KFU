#include <iostream>
#include <string>

int main()
{
	std::string line = " ";
	bool answer = true;

	char tmp = ' ';
	while (tmp != '!')
	{
		std::cin >> tmp;
		if (tmp == '(' || tmp == '{' || tmp == '[') line += tmp;
		if (tmp == ')' || tmp == '}' || tmp == ']')
		{
			switch (tmp)
			{
			case ')':
				if (line.back() == '(') line.replace(line.size()-1, 1, "");
				else answer = false;
				break;
			case '}':
				if (line.back() == '{') line.replace(line.size()-1, 1, "");
				else answer = false;
				break;
			case ']':
				if (line.back() == '[') line.replace(line.size()-1, 1, "");
				else answer = false;
				break;
			}
		}
	}
	if (line != " ") answer = false;
	answer ? std::cout << "YES" : std::cout << "NO";

	return 0;
}
