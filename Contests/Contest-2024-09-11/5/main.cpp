#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	double m;
	double h;

	std::cin >> m >> h;
	std::cout << std::fixed << std::setprecision(32) << m / std::pow(h, 2) << std::endl;

	return 0;
}
