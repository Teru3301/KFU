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
