#include <iostream>

// Ваш код будет вставлен сюда
bool is_prime(int num)
{
	if (num % 2 == 0) return false;

	for (int i = 3; i < num / (i-1); i+=2)
	{
		if (num % i == 0) return false;
	}

	return true;
}


int main(){
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}
