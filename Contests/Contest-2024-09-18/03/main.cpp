#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool compare(std::string num1, std::string num2)
{
	int counter1 = std::count(num1.begin(), num1.end(), '1');
	int counter2 = std::count(num2.begin(), num2.end(), '1');

	if (counter1 == counter2)
	{
		return std::stoi(num1) < std::stoi(num2); 
	}
	else
	{
		return counter1 > counter2;
	}
}

int main(){
    int count;
    std::cin >> count;
    
    std::vector<std::string> nums(count);
    for(auto& line : nums) std::cin >> line;
    
    std::sort(nums.begin(), nums.end(), compare);
    
    for(auto& line : nums) std::cout << line << ' ';
}

