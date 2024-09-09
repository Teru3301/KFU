#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	double a;
	double b;

	std::cin >> a;
	std::cin >> b;

	std::cout << std::setprecision(32) << std::sqrt(std::pow(a, 2) + std::pow(b, 2)) << std::endl;

	return 0;
}
