#include <iostream>
#include <bitset>
#include <iomanip>

union universal_memory
{
	long long znak;
	unsigned long long bez_znak;
	double veshestv;
};

int main()
{
	std::bitset<32> bits;	//	переменная последовательности бит

	bits.reset();			//	обнуление последовательности

	bits.set(0);			//	каждый set задаёт единицу в передаваемый индекс
	bits.set(1);
	bits.set(8);
	bits.set(23);
	bits.set(22);

	for (int i = 0; i < 32; i++) std::cout << bits[i];	//	выводит на экран заданные биты
	std::cout << '\n';

	universal_memory number;
	number.bez_znak = bits.to_ullong();					//	передача беззнакового long long

	setlocale(LC_ALL, "ru");
	std::cout << std::setprecision(64);
	std::cout << "беззнаковое:\t" << number.bez_znak << '\n';
	std::cout << "знаковое:\t" << number.znak << '\n';
	std::cout << "вещественное:\t" << number.veshestv << '\n';

	return 0;
}