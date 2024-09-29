#include <iostream>

int main ()
{
	double a;
	double b;
	double c;

	std::cout << "a: "; std::cin >> a;
	std::cout << "b: "; std::cin >> b;
	std::cout << "c: "; std::cin >> c;

	std::cout << std::min(a, std::min(b, c));

	return 0;
}
