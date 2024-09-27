#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	int tmp;

	std::vector<int>vec;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp;
		vec.push_back(tmp);
	}

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp;
		vec.push_back(tmp);
	}

	std::sort(vec.begin(), vec.end());

	for (auto word : vec) std::cout << word << ' ';

	return 0;
}

