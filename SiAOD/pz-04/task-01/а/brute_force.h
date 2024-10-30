#pragma once

#include <iomanip>
#include <cmath>
#include "../../../../../Cpp/MyFunctions/factorial/factorial.h"

double brute_force (double x, double e)
{
	double k = 0.0;

	double numerator;
	double denumerator;
	double answer = 0.0;
	double member_of_row = e;

	// выполняется до тех пор пока член ряда НЕ ПРЕВОСХОДИТ е
	while (std::fabs(member_of_row) <= e)
	{
		numerator   = std::pow(-1.0, k) * std::pow(x, 2.0 * k + 1.0);
		denumerator = factorial(k) * (2.0 * k + 1.0);

		if (denumerator == 0.0)
		{
			std::cout << "Деление на 0. Вычисление досрочно завершено.\n";
			std::cout << "В ответе будет выведено значени предыдущей итерации\n";
			std::cout << "k = " << k << " f(k) = " << factorial(k) << '\n';
			std::cout << "2 * k + 1 = " << 2.0 * k + 1 << "\n";
			std::cout << "Скорее всего произошел выход за предел типа при вычисление факториала\n";
			break;
		}

		member_of_row = numerator / denumerator;
		answer += member_of_row;
		k += 1.0;
	}

	return answer;
}
