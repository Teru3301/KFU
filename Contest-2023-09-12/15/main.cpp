#include <iostream>

int main()
{
	std::string str;
	std::cin >> str;
	str += ';';

	int counter = 1;

	for (int i = 0; i < str.length()-1; i++)
	{
		if (str[i] == str[i + 1])
		{
			counter++;
		}
		else
		{
			std::cout << str[i];
			if (counter > 1) std::cout << counter;
			counter = 1;
		}
	}

	return 0;
}
