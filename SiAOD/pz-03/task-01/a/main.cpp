#include <iostream>

int main ()
{
	int n;
	double answer = 0.0;
	std::cin >> n;

	for (int i = 0; i < n; i++)
		answer += 1.0 / static_cast<double>(i);

	std::cout << answer;

	return 0;
}
