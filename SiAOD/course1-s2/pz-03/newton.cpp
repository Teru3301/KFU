#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x)
{
    return std::pow(2.0, x) - 4 * x;
}
double df(double x)
{
    return x * std::pow(2, x - 1) - 4;
    //return std::log(2.0) * std::pow(2.0, x) - 4;
}

double df2(double x1, double x2)
{
    return (f(x2) - f(1)) / (x2 - 1);
}

int main ()
{
    double h = 1.0;     //  шаг для поиска отрезка
    int iteration = 1;  //  номер текущей итерации
    double x = 3.5;       //  X
    double px;          //  предыдущее значение X
    double eps = 0.0001;//  точность

    for (; iteration < 100; iteration++)
    {
        px = x;
        x = x - f(x) / df(x);
        std::cout << x << std::endl;
        if (std::fabs(px - x) < eps) break;
    }

    std::cout << "Итерация - " << iteration
        << std::setprecision(6) << std::fixed << "; x = " << x << std::endl;

    return 0;
}
