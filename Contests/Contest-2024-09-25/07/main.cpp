#include <iostream>
#include <fstream>
#include <map>

int main ()
{
	std::map<std::string, int> words;
	std::map<std::string, bool> answer;
	int counter = 0;
	int max = 0;
	std::string target;

	std::ifstream file("data.txt");
	std::cin >> target;
	std::string word = "";
	bool next_word = false;
	while (word != "stopword")
	{
		file >> word;
		if (next_word)
		{
			next_word = false;
			words[word]++;
			if (max < words[word]) max = words[word];
		}
		if (word == target) next_word = true;
	}
	if (!max) std::cout << '-';
	while (max && counter != 3)
	{
		for (auto [word, value] : words)
			if (value == max)
			{
				std::cout << word << ' ';
				counter++;
				if (counter == 3) break;
			}
		max--;
	}

	return 0;
}
