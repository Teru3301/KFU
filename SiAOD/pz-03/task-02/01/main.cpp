#include <iostream>
#include <cmath>
#include "../../../../../Cpp/MyFunctions/timer/timer.h"

double factorial (int i)
{
	double factor = static_cast<double>(i);

	while (--i)
		factor *= static_cast<double>(i);

	if (!factor) factor = 1.0;

	return factor;
}

int main ()
{
	int n = 0;
	double x = 0.0;
	double answer = 1.0;

	std::cout << "n: "; std::cin >> n;
	std::cout << "x: "; std::cin >> x;

	Timer t;
	t.Start();
	

	//	Начало
	for (int i = 1; i <= n; i++)
		answer += (std::pow(x, i) / factorial(i));
	//	Конец

	setlocale(LC_ALL, "ru");
	std::cout << "\nАлгоритм \"в лоб\":\n";
	std::cout << "Прошло времени: " << t.timer_time();
	std::cout << "\n1 + Σ(x^i / i!) = " << answer << '\n';
	
	//	Обнуление переменных
	answer = 1.0;
	double denomenator = 1.0;
	double x_mul = 1.0;
	t.Start();

	//	Начало
	for (int i = 1; i <= n; i++)
	{
		denomenator *= i;
		x_mul *= x;
		answer += x_mul / denomenator;
	}
	//	Конец

	std::cout << "\nОптимизированный алгоритм:\n";
	std::cout << "Прошло времени: " << t.timer_time();
	std::cout << "\n1 + Σ(x^i / i!) = " << answer << "\n\n";

	return 0;
}
