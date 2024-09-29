#include <iostream>
#include <cmath>

int	main ()
{
	double x;
	double y;
	bool in_area = false;

	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;

	if (x <= 0)
		if (std::abs(y) <= 1) in_area = true;
	if (x >= 0)
		if (std::pow(x, 2.0) + std::pow(y, 2.0) <= 1.0) in_area = true;

	setlocale(LC_ALL, "ru");
	in_area ? std::cout << "Точка находится на заданной области" : std::cout << "Точка не находится на заданной области";

	return 0;
}
