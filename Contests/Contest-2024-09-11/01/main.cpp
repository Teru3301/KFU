#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	double pi = std::sqrt(12);
	double tmp = 1.0;
	double n = 3.0;
	for (int i = 1; i <= 5; i++)
	{
		double tmp2 = 1.0 / (n * std::pow(3.0, i));
		i % 2 ? tmp -= tmp2 : tmp += tmp2;
		n += 2;
	}
	pi *= tmp;

	std::cout << std::setprecision(16) << pi;

	return 0;
}
