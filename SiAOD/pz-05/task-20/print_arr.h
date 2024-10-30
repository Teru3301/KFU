#pragma once

#include <iostream>
#include <iomanip>

void print_arr(double *arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << std::setw(5) << arr[i];
	std::cout << '\n';
}
