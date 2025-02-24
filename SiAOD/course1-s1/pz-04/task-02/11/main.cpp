#include <iostream>
#include <cmath>

#include "brute_force.h"
#include "opti.h"

#include "../../../../../Cpp/MyFunctions/timer/timer.h"


int main ()
{
	double x = 0.0;
	double e = 0.0;

	double answer = 0;

	std::cout << "x: "; std::cin >> x;
	std::cout << "e: "; std::cin >> e;

	setlocale(LC_ALL ,"ru");


	Timer timer;

	std::cout << "\nРешение \"в лоб\"\n";
	timer.Start();
	answer = brute_force(x, e);	
	std::cout << "Время: " << timer.timer_time() << '\n';
	std::cout << "Ответ: " << answer << "\n\n";

	std::cout << "Оптимизированное решение\n";
	timer.Start();
	answer = opti(x, e);
	std::cout << "Время: " << timer.timer_time() << '\n';
	std::cout << "Ответ: " <<  answer << "\n\n";

	std::cout << "Вычисление по формуле: " << std::log((1+x)/(1-x)) << "\n\n";

	return 0;
}
