#pragma once

#include <iostream>
#include <iomanip>

void print_arr(double *arr, int n, int ind1, int ind2, int l, int r)
{
	for (int i = 0; i < n; i++)
	{
		if (i < l || i > r) std::cout << "\x1b[32m";
		if (i == ind1 || i == ind2) std::cout << "\x1b[33m";
		std::cout << std::setw(5) << arr[i];
		std::cout << "\x1b[0m";
	}
	std::cout << '\n';
}
