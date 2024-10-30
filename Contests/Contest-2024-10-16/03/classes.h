#pragma once

#include <cmath>

class Shape {
public:
    virtual double getPerimeter() const = 0;
};

class Rectangle : public Shape {
private:
    int a, b;
public:
    Rectangle(int a, int b) {
        this->a = a;
        this->b = b;
    }
    double getPerimeter() const {
        return (a + b) * 2;
    }
};

class Circle : public Shape {
private:
    int r;
public:
    Circle(int r) {
        this->r = r;
    }
    double getPerimeter() const {
        return 2 * M_PI * r;
    }
};

class Triangle : public Shape {
private:
    int a, b, c;
public:
    Triangle(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double getPerimeter() const {
        if ((a + b) <= c || (b + c) <= a || (a + c) <= b) {
            return 0;
        }
        return a + b + c;
    }
};
