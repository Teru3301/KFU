#include <iostream>

int main ()
{
	int n;
	int** arr;

	std::cout << "n - ";
	std::cin >> n;
	arr = new int*[n];
	for (int row = 0; row < n; row++)
	{
		arr[row] = new int[n];
		for (int col = 0; col < n; col++)
			std::cin >> arr[row][col];
	}

	std::cout << '\n';

	int row = n / 2;
	int col = n / 2;

	bool l = false;
	bool r = false;
	bool u = true;
	bool d = false;

	int lb = 0;
	int rb = 0;
	int ub = 0;
	int db = 0;

	while (row < n && col < n && row > -1 && col > -1)
	{
		std::cout << arr[row][col] << ' ';

		if (r)
		{
			if (col + 1 > n / 2 + rb)
			{
				row++;
				db++;
				r = false;
				d = true;
			}
			else
			{
				col++;
			}
		}
		else if (l)
		{
			if (col - 1 < n / 2 - lb)
			{
				row--;
				ub++;
				l = false;
				u = true;
			}
			else
			{
				col--;
			}
		}
		else if (d)
		{
			if (row + 1 > n / 2 + db)
			{
				col--;
				lb++;
				d = false;
				l = true;
			}
			else
			{
				row++;
			}
		}
		else if (u)
		{
			if (row - 1 < n / 2 - ub)
			{
				col++;
				rb++;
				u = false;
				r = true;
			}
			else
			{
				row--;
			}
		}
	}

	return 0;
}
