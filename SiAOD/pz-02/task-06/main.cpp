#include <iostream>

int main ()
{
	int a;
	int b;

	std::cout << "a: "; std::cin >> a;
	std::cout << "b: "; std::cin >> b;

	a > b ? std::cout << a : std::cout << a << ' ' << b;

	return 0;
}
