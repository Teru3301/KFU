#include <iostream>
#include <string>

int main()
{
	long long n;
	std::string word = "";
	std::cin >> n;
	while (n > 0)
	{
		n--;
		word = char((n % 26) + 65) + word;
		n = n / 26;
	}

	std::cout << word;

	return 0;
}
