#include <iostream>
#include <cmath>

int main ()
{
	int n;
	std::cin >> n;
	double answer = 1.0;

	for (int i = 0; i < n; i++)
		answer *= 1.0 + (1.0 / std::pow(i, 2.0));

	std::cout << answer;


	return 0;
}
