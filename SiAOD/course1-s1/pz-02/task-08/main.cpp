#include <iostream>

int main ()
{
	double a;
	double b;
	double c;

	std::cout << "a: "; std::cin >> a;
	std::cout << "b: "; std::cin >> b;
	std::cout << "c: "; std::cin >> c;

	setlocale(LC_ALL, "ru");
	if (a == b && b == c && c == a)
		std::cout << "Равносторонний";
	else if (a == b || b == c || c == a)
		std::cout << "Равнобедренный";
	else
		std::cout << "Разносторонний";

	return 0;
}
