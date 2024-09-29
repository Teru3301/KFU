#include <iostream>
#include <string>
#include <algorithm>

int prio (int symb)
{
	if (symb == '+' || symb == '-') return 1;
	if (symb == '*' || symb == '/' || symb == '%') return 2;
	if (symb == '^') return 3;
	return -1;	//	я сам не знаю почему, но без этого, ничего не работает
}	//	Мб Чабанов какой-то лишний символ добавил, вот оно и не работает

int main ()
{
	std::string str;
	std::string sign_bufer = "";
	std::string result = "";
	bool need_space = false;

	std::cin >> str;

	for (auto symbol : str)
	{
		if (symbol == '(')////////////////////////////////////////////////////
		{											//	обработка скобок	//
			sign_bufer += symbol;					//////////////////////////
			continue;														//
		}																	//
		if (symbol == ')')													//
		{																	//
			while (sign_bufer[sign_bufer.size()-1] != '(')					//
			{																//
				result = result + ' ' + sign_bufer[sign_bufer.size()-1];	//
				sign_bufer.pop_back();										//
			}																//
			sign_bufer.pop_back();											//
			continue;														//
		}/////////////////////////////////////////////////////////////////////
		if (std::isdigit(symbol))/////////////////////////
		{							//	обработка чисел	//
			if (need_space)			//////////////////////
			{											//
				result += ' ';							//
				need_space = false;						//
			}											//
			result += symbol;							//
			continue;									//
		}												//
		need_space = true;////////////////////////////////
		if (sign_bufer.size())////////////////////////////////////////////////////////////////
		{																					//
			while (symbol != '^' && prio(sign_bufer[sign_bufer.size()-1]) >= prio(symbol))	//
			{																				//
				result = result + ' ' + sign_bufer[sign_bufer.size()-1];					//
				sign_bufer.pop_back();														//
				if (!sign_bufer.size()) break;												//
			}																				//
			sign_bufer += symbol;						//////////////////////////////////////
		}												//	обработка арифметических знаков	//
		else sign_bufer += symbol;////////////////////////////////////////////////////////////
	}

	std::reverse(sign_bufer.begin(), sign_bufer.end());			//	дозапись значений	
	for (auto sign : sign_bufer) result = result + ' ' + sign;	//	из буффера

	std::cout << result;
	
	return 0;
}
