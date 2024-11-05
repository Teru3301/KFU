#pragma once

class Employee {
protected:
    std::string name, position;
    int base_money;

public:
    Employee(std::string name, std::string position, int base_money) {
        this->name = name;
        this->position = position;
        this->base_money = base_money;
    }
    virtual int bonus(double percent) const {
        return (int)(base_money * percent + 0.5);
    }
    friend std::ostream& operator<<(std::ostream& os, const Employee& e) {
        os << e.name << " (" << e.position << "): " << e.base_money + e.bonus(bonuses[e.position]);
        return os;
    }
};

class Manager : public Employee {
public:
    Manager(std::string name, int base_money = 16242)
    :Employee(name, "manager", base_money){}

    int bonus(double percent) const {
        if (percent < 0.1) {
            percent = 0.1;
        }
        return (int)(base_money * percent + 0.5);
    }
};

