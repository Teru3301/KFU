#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");

	int N;
	int peak = 2;
	int max_ind = 1;
	int cur_ind = 0;
	int sum_ind = 1;

	std::cin >> N;

	for (int i = 1; i <= N; i++)
	{
		std::cout << i << ' ';
		cur_ind++;

		if (cur_ind == max_ind)
		{
			std::cout << '\n';
			max_ind += sum_ind;
			cur_ind = 0;
			if (max_ind == 1 || max_ind == peak)
			{
				if (sum_ind > 0) peak++;
				sum_ind *= -1;
			}
		}
	}

	return 0;
}
