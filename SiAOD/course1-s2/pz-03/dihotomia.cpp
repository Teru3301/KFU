//  Решение нелинейных уравнений
//  Медод дихотомии
//
//  суть метода
//  - найти отрезок [a b] на котором есть корень
//      то есть f(a) * f(b) < 0
//  - вычислить f(c) где c = (a + b) / 2
//  - уменьшить отрезок с корнем
//      если f(c) < 0, то a = c    (для возрастающей функции)
//      есть f(с) > 0, то b = c    (для возрастающей фукнции)
//  - продолжать предыдущие шаги до тех пор пока отрезок [a b] не станет меньше заданной точности


#include <iostream>
#include <cmath>
#include <iomanip>


double f(double x)
{
    return std::pow(2, x) - 4 * x;
}

int main()
{
    double a, b;            //  отрезок для поиска корня
    double h = 1.0;         //  шаг для поиска отрезка [a b]
    double eps = 0.0001;    //  точность
    double c;               //  искомый x
    double iteration = 1;   //  номер итерации приближения


    std::cout << "Поиск отрезка  [a b]" << std::endl;
    a = 2.5;
    while (true)
    {
        b = a + h;
        if (f(a) * f(b) < 0) break;
        a += h;
    }
    std::cout << "Найден отрезок [" << a << " " << b << "]" << std::endl;


    std::cout << "Вычисление x..." << std::endl;
    for (; iteration < 1000; iteration++)
    {
        c = (a + b) / 2;                    //  текущее значение x
        if (std::fabs(b - a) < eps) break;  //  заданная точность была достигнута

        if (f(c) > 0)
        {
            if (f(a) < f(b)) b = c;
            else a = c;
        } else {
            if (f(a) < f(b)) a = c;
            else b = c;
        }
    }


    std::cout << "Итерация - " << iteration
        << std::setprecision(6) << std::fixed << "; x = " << c << std::endl;

    return 0;
}
