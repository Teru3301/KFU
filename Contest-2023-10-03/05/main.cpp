#include <iostream>
#include <map>

int main()
{
	int n;
	int max = 0;
	std::cin >> n;
	
	std::map<std::string, int> word;

	for (int i = 0; i < n; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		word[tmp]++;
		if (max < word[tmp]) max = word[tmp];
	}

	for (const auto& [key, value] : word)
		if (value == max) std::cout << key << ' ';

	return 0;
}
