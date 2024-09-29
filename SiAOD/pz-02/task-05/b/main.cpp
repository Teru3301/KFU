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

	w = x - (std::pow(x, 2.0) / (1 + std::pow((std::sin((x + y + z))), 2.0)));

	std::cout << "w: " << w;

	return 0;
}
