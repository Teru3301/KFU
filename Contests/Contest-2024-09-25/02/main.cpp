#include <iostream>
#include <string>

int main ()
{
	char inp;
	std::string str;
	bool answer = true;

	while (true)
	{
		std::cin >> inp;
		if (inp == '!') break;
		if (inp == '(' || inp == '{' || inp == '[') str += inp;
		if (inp == ')' || inp == '}' || inp == ']')
		{
			if (inp == ')') inp = '(';
			if (inp == '}') inp = '{';
			if (inp == ']') inp = '[';
			if (str.size())
				if (inp == str.at(str.size()-1)) str.pop_back();
				else {answer = false; break;}
		}
	}

	if (str.size()) answer = false;

	answer ? std::cout << "YES" : std::cout << "NO";

	return 0;
}
