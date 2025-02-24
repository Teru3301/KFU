#include <iostream>
#include <cmath>

int main()
{
	double x;
	double y;
	double z;

	double w;

	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;
	std::cout << "x: "; std::cin >> z;

	w = std::cos(std::pow(z, 2.0) + (std::pow(x, 2.0) / 4.0) + y);

	std::cout << "w: " << w;

	return 0;
}
