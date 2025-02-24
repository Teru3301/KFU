#include <iostream>

int main ()
{
	double x;
	double y;
	bool in_area = false;

	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;

	if (y >= -0.5 && x >= y) in_area = true;

	setlocale (LC_ALL, "ru");
	in_area ? std::cout << "Точка находится на заданной области" : std::cout << "Точка не находится на заданной области";	

	return 0;
}
