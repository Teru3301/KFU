#include <iostream>

// Ваш код здесь


class Vector;

class Point {
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void move(Vector vect);
};

class Vector {
public:
    int x, y;
    Vector(Point p1, Point p2) {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }
};

void Point::move(Vector vect) {
    x += vect.x;
    y += vect.y;
}


int main(){
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    Point p(x1, y1);
    Vector dir(Point(x2, y2), Point(x3, y3));
    p.move(dir);
    
    std::cout << p.x << ' ' << p.y;
}
