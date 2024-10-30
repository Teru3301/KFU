#pragma once

#include <iomanip>
#include <cmath>
#include "../../../../../Cpp/MyFunctions/factorial/factorial.h"

double brute_force (double x, double e)
{
	double answer = 0.0;
	double member = 1;

	std::cout << std::setprecision(64);

	int k = 1;

	for (; std::fabs(member) >= e; k++)
	{
		answer += member;
		member = std::pow(-x, 2*k) / (2 * factorial(k));
	}

	std::cout << "\n k - " << k << '\n';

	return answer;
}
