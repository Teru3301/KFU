#include <iostream>
#include <cmath>

int main ()
{
	double a;
	double b;
	double c;

	double p;

	std::cout << "a: "; std::cin >> a;
	std::cout << "b: "; std::cin >> b;
	std::cout << "c: "; std::cin >> c;

	p = (a + b + c) / 2.0;

	setlocale(LC_ALL, "ru");
	std::cout << "Площадь: " << std::sqrt(p * (p - a) * (p - b) * (p - c));

	return 0;
}
