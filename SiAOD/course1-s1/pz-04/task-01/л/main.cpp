#include <iostream>
#include <iomanip>

#include "brute_force.h"
#include "opti.h"
#include "../../../../../Cpp/MyFunctions/timer/timer.h"

int main ()
{
	double x;
	double e;
	double answer = 0.0;

	std::cout << "x: "; std::cin >> x;
	std::cout << "e: "; std::cin >> e;
	std::cout << std::setprecision(64);

	std::cout << std::setprecision(64);

	setlocale(LC_ALL, "ru");
	Timer timer;

	std::cout << "Алгоритм \"в лоб\":\n";
	timer.Start();
	answer = brute_force(x, e);
	std::cout << "Время выполнения: " << timer.timer_time() << '\n';
	std::cout << "Ответ: " << answer << "\n\n";

	std::cout << "Оптимизированный алгоритм:\n";
	timer.Start();
	answer = opti(x, e);
	std::cout << "Время выполнения: " << timer.timer_time() << '\n';
	std::cout << "Ответ: " << answer << "\n\n";

	return 0;
}
