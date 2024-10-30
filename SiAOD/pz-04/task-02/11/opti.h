#pragma once

#include <cmath>

double opti (double x, double e)
{
	double res = 0;
	double xx = x;
	double x_x = x * x;
	double k = 1.0;
	double member = x;

	while (std::fabs(member) >= e)
	{
		res += member;
		xx = xx * x_x;
		k += 2;
		member = xx / k;
	}

	return res * 2;
}


