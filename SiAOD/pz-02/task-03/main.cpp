#include <iostream>
#include <cmath>

struct point
{
	double x;
	double y;
};

int main ()
{
	point a;
	point b;

	setlocale(LC_ALL, "ru");

	std::cout << "Первая точка\nx: "; std::cin >> a.x; std::cout << "y: "; std::cin >> a.y;
	std::cout << "Вторая точка\nx: "; std::cin >> b.x; std::cout << "y: "; std::cin >> b.y;
	
	double leg1 = std::abs(std::max(a.x, b.x) - std::min(a.x, b.x));
	double leg2 = std::abs(std::max(a.y, b.y) - std::min(a.y, b.y));

	std::cout << "Расстояние: " << std::sqrt(std::pow(leg1, 2.0) + std::pow(leg2, 2.0)); 

	return 0;
}
