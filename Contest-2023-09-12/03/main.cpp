#include <iostream>
#include <iomanip>

int main()
{
	double a;
	double b;

	std::cin >> a;
	std::cin >> b;
	std::cout << std::setprecision(32) << a / b << std::endl;

	return 0;
}
