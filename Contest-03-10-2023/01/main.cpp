#include <iostream>

int main()
{
	int n;
	double* a;
	int m;
	double* b; 

	std::cin >> n;
	a = new double[n];
	for (int i = 0; i < n; i++) std::cin >> a[i];

	std::cin >> m;
	b = new double[m];
	for (int i = 0; i < m; i++) std::cin >> b[i];

	double* c = new double[n+m];
	int it_a = 0;
	int it_b = 0;
	for (int i = 0; i < n+m; i++)
	{
		if (it_a >= n)
		{
			c[i] = b[it_b];
			it_b++;
			continue;
		}
		if (it_b >= m)
		{
			c[i] = a[it_a];
			it_a++;
			continue;
		}
		if (a[it_a] < b[it_b])
		{
			c[i] = a[it_a];
			it_a++;
		}
		else {
			c[i] = b[it_b];
			it_b++;
		}
	}

	for (int i = 0; i < n+m; i++)
	{
		std::cout << c[i] << ' ';
	}

	return 0;
}
