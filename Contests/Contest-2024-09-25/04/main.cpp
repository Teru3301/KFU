#include <iostream>
#include <map>

int main ()
{
	int n;
	int m;

	std::map<std::string, bool> words;
	std::map<std::string, bool> general;
	std::string tmp;

	std::cin >> n;
	for	(int i = 0; i < n; i++)
	{
		std::cin >> tmp;
		words[tmp] = true;
	}

	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::cin >> tmp;
		if (words[tmp]) general[tmp] = true;
	}

	bool no_have_general = true;
	for (auto [word, _] : general)
	{
		std::cout << word << ' ';
		no_have_general = false;
	}
	if (no_have_general) std::cout << -1;

	return 0;
}
