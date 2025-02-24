#include <iostream>
#include <cmath>

int main ()
{
	double x;

	std::cout << "x: "; std::cin >> x;

	if (x >= -2.0 && x <= 2.0) std::cout << "y: " << std::pow(x, 2);
	else std::cout << "y: 4";

	return 0;
}
