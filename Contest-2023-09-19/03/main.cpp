#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// Ваш код будет вставлен сюда
int counter(std::string str)
{
    int countr = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1') countr++;
    }
    return countr;
}

bool compare(std::string first, std::string second)
{
    if (first == second) return 0;

    int counter_1, counter_2;
    counter_1 = counter(first);
    counter_2 = counter(second);

    if (counter_1 == counter_2)
    {
        if (std::stoi(first) < std::stoi(second)) return true;
        if (std::stoi(first) > std::stoi(second)) return false;
    }
    else
    {
        if (counter_1 > counter_2) return true;
        if (counter_1 < counter_2) return false;
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
