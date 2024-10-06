#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

// Ваш код будет вставлен сюда
std::string get_value(std::string &line)
{
	std::string value = "";
	for (auto symb : line)
	{
		if (symb == ';') break;
		value += symb;	
	}
	line.replace(0, value.size()+1, "");
	return value;
}

Student make_student (std::string line)
{
	Student student;

	student.name = get_value(line);
	student.group = get_value(line);

	while (line != "")
	{
		Course course;
		course.name = get_value(line);
		course.semester = std::stoi(get_value(line));
		course.finished = std::stoi(get_value(line));
		student.courses.push_back(course);
	}

	return student;
}

bool is_upper (Student student1, Student student2)
{
	if (student1.group == student2.group)
		return student1.name < student2.name;
	return student1.group < student2.group;
}

bool is_debtor (Student student, int cur_semester, int max_debt)
{
	int curent_debt = 0;
	for (auto course : student.courses)
		if (cur_semester != course.semester)
			if (!course.finished) curent_debt++;

	return curent_debt > max_debt;
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
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(stud_count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
                 students.end(),
                 std::back_inserter(expulsion_candidates),
                 [cur_semester, max_debt](const Student& student){
                     return is_debtor(student, cur_semester, max_debt);
                 });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);
}
