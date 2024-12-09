#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	int m;
	std::vector<std::vector<int>> matr;

	setlocale(LC_ALL, "ru");

	std::cout << "кол-во строк\nкол-во столбцов\n";
	std::cin >> n >> m;
	std::cout << "матрица\n";
	for (int row = 0; row < n; row++)
	{
		std::vector<int> tmp_matr;
		for (int col = 0; col < m; col++)
		{
			int tmp;
			std::cin >> tmp;
			tmp_matr.push_back(tmp);
		}
		matr.push_back(tmp_matr);
	}

	for (int row = 0; row < n; row++)
	{
		std::vector<int> tmp_v = matr[row];
		std::sort(tmp_v.begin(), tmp_v.end());

		for (int col = 0; col < m; col++)
		{
			if (matr[row][col] == tmp_v[0])
			{
				bool sedlovoi = true;
				for (int row2 = 0; row2 < n; row2++)
				{
					if (matr[row][col] < matr[row2][col])
						sedlovoi = false;
				}
				if (sedlovoi)
				{
					std::cout << "седловой элемент в [строке][столбце] ["
						<< row + 1 << "][" << col + 1 << "] - " << matr[row][col] << '\n';
				}
			}
		}
	}

	return 0;
}
