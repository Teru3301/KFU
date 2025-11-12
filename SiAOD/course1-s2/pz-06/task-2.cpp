
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


class Point {
public:
    double x;
    double y;

    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }

    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }

    Point operator*(double scalar) const {
        return {x * scalar, y * scalar};
    }

    Point operator/(double scalar) const {
        return {x / scalar, y / scalar};
    }
};



//  Функция Розенброка
//  Минимум в точке (1, 1) = 0
double f(const Point& point)
{
    return std::pow(1.0 - point.x, 2.0) + 100 * std::pow(point.y - std::pow(point.x, 2.0), 2.0);
}



Point nelder_mid(std::vector<Point>& simplex, double eps, int max_iter)
{
    int bad = simplex.size() - 1;

    for (int iter = 0; iter < max_iter; ++iter)
    {
//  сортировка точек симплекса
        std::sort(simplex.begin(), simplex.end(), 
            [](const Point& a, const Point& b){return f(a) < f(b);}
            );

//  вычисление центра тяжести для всех точек кроме худшей
        Point centroid = (simplex[0] + simplex[1]) / 2.0;

//  отражение
        Point reflected = centroid + (centroid  - simplex[bad]);


//  растяжение
//  Выполняется когда отраженная точка оказалась лучше всех текущих точек симплекса
        if (f(reflected) < f(simplex[0]))
        {
            Point expanded = centroid + (reflected - centroid) * 2.0;
            simplex[bad] = (f(expanded) < f(reflected) ? expanded : reflected);
        }

//  Принятие отраженной точки
//  Выполняется, когда отраженная точка лучше, чем вторая по качеству точка,  но не лучше лучшей 
        else if (f(reflected) < f(simplex[1]))
        {
            simplex[bad] = reflected;
        }

//  сжатие
        else
        {
            Point expanded = centroid + (simplex[bad] - centroid) * 0.5;
            if (f(expanded) < f(simplex[bad])) {
                simplex[2] = expanded;
            } else {
                // Сжатие всего симплекса к лучшей точке
                simplex[1] = simplex[0] + (simplex[1] - simplex[0]) * 0.5;
                simplex[2] = simplex[0] + (simplex[2] - simplex[0]) * 0.5;
            }
        }


//  проверка достижения точности
        double max_diff = 0.0;
        for (const auto& p : simplex) {
            double diff = std::sqrt(std::pow(p.x - simplex[0].x, 2.0) + std::pow(p.y - simplex[0].y, 2.0));
            if (diff > max_diff)
                max_diff = diff;
        }
        if (max_diff < eps) {
            std::cout << "Пройдено итераций         - " << iter << std::endl;
            break;
        }
    }

    return simplex[0];
}



int main ()
{
    Point point = {3, -2};
    std::vector<Point> simplex = {
        point, 
        point + Point{0.5, 0.0},
        point + Point{0.0, 0.5}
    };

    Point answer = nelder_mid(simplex, 0.000001, 10000);


    std::cout << "Точка минимума            - " << answer.x << ", " << answer.y << std::endl;
    std::cout << "Значение в точке минимума - " << std::fixed << f(answer) << std::endl;

    return 0;
}



