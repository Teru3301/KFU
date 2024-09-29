#include <iostream>
#include <cmath>

int main ()
{
	double x;

	std::cout << "x: "; std::cin >> x;

	if (x <= 2) std::cout << "y: " << std::pow(x, 2.0) + 4.0*x + 5;
	else std::cout << 1.0 / (std::pow(x, 2.0) + 4.0*x + 5);

	return 0;
}
