#include <iostream>
#include <cmath>

int main()
{
	std::cout << sqrt(12) * (1 - (1.0f / (3 * 3)) + (1.0f / (5 * pow(3, 2))) - (1.0f / (7 * pow(3, 3))) + (1.0f / (9 * pow(3, 4))) - (1.0f / (11 * pow(3, 5))));

	return 0;
}
