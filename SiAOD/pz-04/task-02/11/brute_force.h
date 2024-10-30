#pragma once

#include <cmath>

double brute_force (double x, double e)
{
	double res = 0;
	double member = x;
	int i = 1;

	while (std::fabs(member) >= e)
	{
		res += member;
		i += 2;
		member = std::pow(x, i) / static_cast<double>(i);
	}

	return res * 2;
}
