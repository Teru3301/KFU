#include <iostream>
#include <cmath>

int main ()
{
	int n;
	double* arr;
	double max = 0;

	std::cin >> n;

	arr = new double[n];
	for	(int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		if (std::fabs(arr[i]) > max) max = std::fabs(arr[i]);
	}
	
	for (int i = 0; i < n; i++)
		std::cout << arr[i] / max << ' ';

	return 0;
}
