#include <iostream>
#include <fstream>
#include "json.hpp"

int main ()
{
	std::ifstream file("data.json");
	nlohmann::json josn_object;
	file >> josn_object;
	file.close();

	int user_id;
	int completed_tasks = 0;

	std::cin >> user_id;

	for (auto project : josn_object)
		for (auto task : project["tasks"])
			if (task["user_id"] == user_id)
				if (task["completed"]) completed_tasks++;

	std::cout << completed_tasks;

	return 0;
}
