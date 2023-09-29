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
Student make_student(std::string line)
{
    Student ns;

    while (line[0] != ';')
    {
        ns.name += line[0];
        line.replace(0, 1, "");
    }
    line.replace(0, 1, "");
    while (line[0] != ';')
    {
        ns.group += line[0];
        line.replace(0, 1, "");
    }
    line.replace(0, 1, "");
    
    while (line.length())
    {
        Course cr;
        
        while (line[0] != ';')
        {
            cr.name += line[0];
            line.replace(0, 1, "");
        }
        line.replace(0, 1, "");
        cr.semester = (int)line[0] - '0';
        line.replace(0, 2, "");
        cr.finished = (int)line[0] - '0';
        line.replace(0, 2, "");

        ns.courses.push_back(cr);
    }

    return ns;
}

bool is_debtor(Student st, int cur, int max)
{
    int counter = 0;
    int it = 0;
    while (it < st.courses.size())
    {
        if (st.courses[it].semester < cur)
        {
            if (!st.courses[it].finished) counter++;
        }
        it++;
    }
    if (counter > max) return true;
    return false;
}

bool is_upper(Student st1, Student st2)
{
    if (st1.group == st2.group) return st1.name < st2.name;
    return st1.group < st2.group;
}

void print(std::vector<Student> students)
{
    if (students.size() == 0)
    {
        std::cout << "Empty list!";
        return;
    }

    std::cout << students[0].group << std::endl;
    std::cout << "- " << students[0].name << std::endl;

    for (int i = 1; i < students.size(); i++)
    {
        if (students[i].group != students[i - 1].group) std::cout << students[i].group << std::endl;
        std::cout << "- " << students[i].name << std::endl;
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
