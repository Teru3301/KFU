#include "classes.h"

#include <iostream>

int main ()
{
	Box box;
	Cat cat = box.open();

	std::cout << cat.is_alive();

	return 0;
}
