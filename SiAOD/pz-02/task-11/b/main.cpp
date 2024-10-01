#include <iostream>
#include <cmath>

int main ()
{
	double x;
	double y;
	bool in_area = false;

	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;

	if (y >= -0.5)
		if (y <= x)
		{
			if (x <= 1.0) in_area = true;
			if (std::pow(x-1.0, 2.0) + std::pow(y, 2.0) <= 1.0) in_area = true;
		}
	setlocale (LC_ALL, "ru");
	in_area ? std::cout << "Точка находится на заданной области" : std::cout << "Точка не находится на заданной области";

	return 0;
}
