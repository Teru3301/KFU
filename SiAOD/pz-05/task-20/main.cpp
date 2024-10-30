#include <iostream>
#include "print_arr.h"

int main ()
{
	int n;
	double *arr;

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	double tmp;
	bool done;
	while (true)
	{
		done = true;
		for (int i = 1; i < n; i++)
		{
			if (arr[i - 1] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
				done = false;
			}
			print_arr(arr, n);
		}
		if (done) break;
		done = true;
		for (int i = n - 1; i > 1; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
				done = false;
			}
			print_arr(arr, n);
		}
		if (done) break;
	}


	print_arr(arr, n);



	return 0;
}
