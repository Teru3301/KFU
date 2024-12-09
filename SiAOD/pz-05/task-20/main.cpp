#include <iostream>
#include "print_arr.h"

int main ()
{
	int n;
	double *arr;

	std::cin >> n;
	arr = new double[n];
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	int l_border = 0;
	int r_border = n - 1;
	bool changed = true;
	int tmp;

	while (changed)
	{
		changed = false;
		int bord;
		//	проход с лева на право
		for (int i = l_border; i < r_border; i++)
		{
			if (arr[i] > arr[i+1])
			{
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
		
				std::cout << ">>> ";
				print_arr(arr, n, i, i+1, l_border, r_border);
				changed = true;
				bord = i;
			}
		}
		r_border = bord;

		//	проход с права на лево
		for (int i = r_border; i > l_border; i--)
		{
			if (arr[i] < arr[i-1])
			{
				tmp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = tmp;
			
				std::cout << "<<< ";
				print_arr(arr, n, i, i-1, l_border, r_border);
				changed = true;
				bord = i;
			}
		}
		l_border = bord;
	}


	std::cout << '\n';
	print_arr(arr, n, -1, -1, l_border, r_border - 1);

	return 0;
}
