Student make_student(std::string line)
{
    Student ns; // new student
    ns.name = line;
    ns.group = line;

    ns.name.replace(ns.name.find(';'), ns.name.length() - ns.name.find(';'), "");
    ns.group.replace(0, ns.group.find(';')+1, "");

    return ns;
}

bool is_upper(Student st1, Student st2)
{
    if (st1.group == st2.group)
    {
        return st1.name < st2.name;
    }

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
