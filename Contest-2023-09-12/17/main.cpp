#include <iostream>

int n;
int* N;
int water = 0;

void func(int height)
{
	int tmp = -1;
	for (int i = 0; i < n; i++)
	{
		if (N[i] >= height)
		{
			if (tmp != -1) water += tmp;
			tmp = 0;
		}
		else if (tmp != -1) tmp++;
	}
}

int main()
{
	int max = 0;

	std::cin >> n;
	N = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> N[i];
		if (N[i] > max) max = N[i];
	}

	int height = 2;
	while (height < max+1)
	{
		func(height);
		height++;
	}
	std::cout << water;
	
	return 0;
}
