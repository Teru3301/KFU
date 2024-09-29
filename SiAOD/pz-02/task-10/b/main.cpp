#include <iostream>
#include <cmath>

int main ()
{
	double x;

	std::cout << "x: "; std::cin >> x;

	if (x <= 0) std::cout << "y: 0";
	else if (x <= 1) std::cout << "y: " << x;
	else std::cout << std::pow(x, 4.0);

	return 0;
}
