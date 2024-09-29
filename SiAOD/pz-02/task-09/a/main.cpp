#include <iostream>

int main ()
{
	double x;
	double y;
	double z;

	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;
	std::cout << "z: "; std::cin >> z;

	std::cout << std::max(x+y+z, x*y*z) + 3;

	return 0;
}
