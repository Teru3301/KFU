#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};

// Ваш код будет вставлен сюда
Student make_student (std::string line)
{
	Student student;

	student.name = line;
	student.group = line;

	student.name.replace(line.find(';'), line.length() - line.find(';'), "");
	student.group.replace(0, line.find(';')+1, "");

	return student;
}

bool is_upper (Student student1, Student student2)
{
	if (student1.group == student2.group)
		return student1.name < student2.name;
	return student1.group < student2.group;
}

void print (std::vector<Student> students)
{
	if (!students.size())
	{
		std::cout << "Empty list!";
		return;
	}
	std::string curent_group = "";
	for (auto student : students)
	{
		if (curent_group != student.group)
		{
			curent_group = student.group;
			std::cout << curent_group << '\n';
		}
		std::cout << "- " << student.name << '\n';
	}
}


int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline
    
    std::vector<Student> students(count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::sort(students.begin(), students.end(), is_upper);
    
    print(students);
}
