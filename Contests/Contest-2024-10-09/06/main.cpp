#include <iostream>
#include <string>

// Ваш код будет вставлен сюда

#include "classes.h"

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);	
    std::getline(std::cin, num, 'j');
    Complex c2(num);
   
	std::cout << c1+c2 << '\n' << c1-c2 << '\n'
              << c1*c2 << '\n' << c1/c2 << std::endl;
}
