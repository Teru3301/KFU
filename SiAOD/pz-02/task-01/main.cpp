#include <iostream>
#include <cmath>

int main ()
{
	int x;
	int y;

	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;

	std::cout << "answer: " << ( std::abs(x) - std::abs(y) ) / (1.0 + std::abs(x*y));

	return 0;
}
