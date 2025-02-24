#include <iostream>
#include "../../../../../Cpp/MyFunctions/timer/timer.h"

int main ()
{
	int n;
	double answer = 0.0;
	std::cin >> n;

	Timer timer;

	setlocale(LC_ALL, "ru");
	
	std::cout << "Решение \"в лоб\"\n";
	timer.Start();
	
	for (int i = 1; i <= n; i++)
		answer += 1.0 / static_cast<double>(i);

	std::cout << "Время выполнения: " << timer.timer_time() << '\n';
	std::cout << "Ответ: " << answer;

	return 0;
}
