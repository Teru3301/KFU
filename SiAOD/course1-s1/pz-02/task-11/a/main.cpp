#include <iostream>
#include <cmath>

int main ()
{
	double x;
	double y;
	bool in_area = false;

	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;

	if (std::pow(x, 2.0) + std::pow(y, 2.0) <= 1.0)
		if (x >= -y) in_area = true;

	setlocale (LC_ALL, "ru");
	in_area ? std::cout << "Точка находится в заданной области" : std::cout << "Точка не находится в заданной области";

	return 0;
}
