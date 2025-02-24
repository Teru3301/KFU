#include <iostream>
#include <cmath>

int main ()
{
	double x;
	double y;
	double z;

	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;
	std::cout << "z: "; std::cin >> z;

	std::cout << std::min(std::pow(x, 2.0) + std::pow(y, 2.0), std::pow(y, 2.0) + std::pow(z, 2.0)) - 4;

	return 0;
}
