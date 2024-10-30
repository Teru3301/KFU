#include <iostream>
#include "fill.h"

int main ()
{
	int n;
	int* arr;

	std::cin >> n;
	fill(arr, n);

	bool vozrast = true;
	bool ubivaus = true;
	bool no_vozr = true;
	bool no_ubiv = true;

	for (int i = 1; i < n; i++)
	{
		vozrast = (arr[i - 1] >= arr[i] ? false : vozrast);
		ubivaus = (arr[i - 1] <= arr[i] ? false : ubivaus);
		no_vozr = (arr[i - 1] < arr[i] ? false : no_vozr);
		no_ubiv = (arr[i - 1] > arr[i] ? false : no_ubiv);
	}

	setlocale(LC_ALL, "ru");

	std::cout << "Возрастающая: " << vozrast << '\n';
	std::cout << "Убывающая: " << ubivaus << '\n';
	std::cout << "Не возрастающая: " << no_vozr << '\n';
	std::cout << "Не убывающая: " << no_ubiv << '\n';

	return 0;
}
