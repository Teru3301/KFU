#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
	std::map <std::string, int> line;
	
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		if (!line[tmp]) line[tmp]++;
	}
	
	std::vector<std::string> words;

	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		if (line[tmp])
		{
			line[tmp] = 0;
			words.push_back(tmp);
		}
	}

	std::sort(words.begin(), words.end());
	for (int i = 0; i < words.size(); i++) std::cout << words[i] << ' ';
	if (!words.size()) std::cout << "-1";

	return 0;
}
