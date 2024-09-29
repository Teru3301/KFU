#include <iostream>
#include <cmath>

int main ()
{
	double x;
	double y;
	double z;

	double w;

	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;
	std::cout << "z: "; std::cin >> z;

	w = y + x - (std::pow((std::cos(x)), 2.0) / (1 + std::sqrt(std::abs(y + z))));

	std::cout << "w: " << w;

	return 0;
}
