

void auto_fill (int* &arr, int n)
{
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n\n";
}

void fill (int* &arr, int n)
{
	arr = new int[n];
	for	(int i = 0; i < n; i++)
		std::cin >> arr[i];
}
