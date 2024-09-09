#include <iostream>

int main()
{
	int n;
	long long* arr;
	long water = 0;
	int max_i = 0;

	std::cin >> n;
	arr = new long long[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		if (arr[i] > arr[max_i]) max_i = i;
	}

	long long localMax;
	
	localMax = arr[0];
	for (int i = 1; i < max_i; i++)
	{
		if (arr[i] >= localMax)
		{
			localMax = arr[i];
			continue;
		}
		water += localMax - arr[i];
	}
	localMax = arr[n-1];
	for (int i = (n-2); i > max_i; i--)
	{
		if (arr[i] >= localMax)
		{
			localMax = arr[i];
			continue;
		}
		water += localMax - arr[i];
	}

	std::cout << water;

	return 0;
}
