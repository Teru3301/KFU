#include <iostream>
#include <fstream>
#include <map>

std::string get_value (std::string &line)
{
	std::string value;
	bool quotes = false;
	for (auto symb : line)
	{
		if (!quotes && symb == ',') break;
		if (symb == '"') quotes = !quotes;
		value += symb;
	}
	line.replace(0, value.size()+1, "");
	if (!value.size() || value == "\"\"") value = "0";
	else if (value.at(0) == '"')
	{
		value.replace(0, 1, "");
		value.replace(value.size()-1, 1, "");
		while (value.find("\"\"") != std::string::npos)
			value.replace(value.find("\"\""), 2, "\"");
	}
	return value;
}

int main ()
{
	std::ifstream file("train.csv");
	std::map<int, std::map<std::string, std::string>> passanger;// age(name, sex)
	std::string line;
	int age;
	int pclass;

	std::cin >> pclass >> age;

	std::getline(file, line, '\r');
	while (!file.eof())
	{
		std::getline(file, line, '\r');
		//	пропуск не нужной информации
		get_value(line); get_value(line);
		//	заполнение информации о пассажире
		int pclass_ = std::stoi(get_value(line));
		std::string name_ = get_value(line);
		std::string sex_ = get_value(line);
		int age_ = std::stoi(get_value(line));
		//	добавление подходящих пассажиров
		if (pclass_ == pclass && sex_ == "female" && age_ > age)
			passanger[age_][name_] = sex_;
	}
	file.close();

	for (auto [age, map] : passanger)
		for (auto [name, sex] : map)
			std::cout << name << '\n';
	
	return 0;
}

