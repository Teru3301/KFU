#include <iostream>
#include <cmath>

int main ()
{
	double a;
	double b;

	std::cout << "a: "; std::cin >> a;
	std::cout << "b: "; std::cin >> b;

	setlocale(LC_ALL, "ru");

	std::cout << "Среднее арефметическое кубов a и b:   " << (std::pow(a, 3) + std::pow(b, 3)) / 2.0 << '\n';
	std::cout << "Среднее геометрическое модулей a и b: " << std::sqrt((std::abs(a) * std::abs(b)));

	return 0;
}
