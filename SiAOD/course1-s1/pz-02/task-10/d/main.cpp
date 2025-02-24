#include <iostream>
#include <cmath>

#define pi 3.14

int main ()
{
	double x;

	std::cout << "x: "; std::cin >> x;
	
	if (x <= 0) std::cout << "y: 0";
	else if (x <= 1) std::cout << "y: " << std::pow(x, 2.0);
	else std::cout << std::pow(x, 2.0) - std::sin(pi*std::pow(x, 2.0)) - 1;

	return 0;
}
