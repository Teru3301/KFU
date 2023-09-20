#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> str;
	while (true)
	{
		std::string tmp;
		std::cin >> tmp;
		if (tmp == "end") break;
		str.push_back(tmp);
	}
	sort(str.begin(), str.end());
	std::string tmp = "";
	for (int i = 0; i < str.size()-1; i++)
	{
		if (str[i] == str[i + 1] && str[i] != tmp)
		{
			std::cout << str[i] << ' ';
			tmp = str[i];
		}
	}
	return 0;
}
