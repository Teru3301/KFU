#include <iostream>
#include <string>

// Ваш код здесь

#include "classes.h"

int main() {
	std::string a, b;
    std::cin >> a >> b;

    Bigint first(a);
    Bigint second(b);

    std::cout << "a + b = " << (first + second) << std::endl;
    std::cout << "a - b = " << (first - second) << std::endl;
    std::cout << "a * b = " << (first * second) << std::endl;
    std::cout << "a / b = " << (first / second) << std::endl;

    int c;
    std::cin >> c;
    Bigint third(c);
    Bigint zero;

    std::cout << "с > 0 = " << (third > zero) << std::endl;
    std::cout << "с < 0 = " << (third < zero) << std::endl;
    std::cout << "с == 0 = " << (third == zero) << std::endl;

	return 0;
}
