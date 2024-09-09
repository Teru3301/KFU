#include <iostream>

int main()
{
	int A;
	int B;
	int C;

	std::cin >> A >> B >> C;

	if (abs(A - B) < abs(A - C))
	{
		std::cout << "B " << abs(A - B);
	}
	else
	{
		std::cout << "C " << abs(A - C);
	}

	return 0;
}
