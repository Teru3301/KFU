//  Решение систем нелинейных уравнений
//  Обратнвя квадротичная интерполяция для поиска минимума функции
//
//  Интерполяция - поиск значения между точками
//  Квадратичная интерполяция - поиск значниея между точками при помощи параболы
//  Обратная квадротичная интерполяция - 

#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    return pow(2.0, x) - 4 * x;
}

double df(double x)
{
    return log(2.0) * pow(2.0, x) - 4.0;
}

// Обратная квадратичная интерполяция
double inverseQuadraticInterpolation(double x0, double x1, double x2) {
    double y0 = df(x0);
    double y1 = df(x1);
    double y2 = df(x2);

    double term0 = x0 * (y1 * y2) / ((y0 - y1) * (y0 - y2));
    double term1 = x1 * (y0 * y2) / ((y1 - y0) * (y1 - y2));
    double term2 = x2 * (y0 * y1) / ((y2 - y0) * (y2 - y1));

    return term0 + term1 + term2;
}

int main() {
    double x0 = -1.0;            //  для параболы
    double x1 = 0.0;            //  для параболы
    double x2 = 1.0;            //  для параболы
    double eps = 0.0001;        //  точность
    double x = 0;               //  корень
    double prev_x;              //  предыдущее значние корня (для вычисления точности)
    size_t iteration = 1;       //  номер итерации

    prev_x = std::numeric_limits<double>::infinity();

    std::cout << std::fixed << std::setprecision(6);
    for (; iteration < 100; iteration++) {
        x = inverseQuadraticInterpolation(x0, x1, x2);
        std::cout << "Итерация - " << iteration << ": x ≈ " << x << ", f(x) = " << f(x) << std::endl;

        x0 = x1;
        x1 = x2;
        x2 = x;

        if (std::fabs(prev_x - x) < eps) break;
        prev_x = x;
    }

    std::cout << "минимум: x ≈ " << x << std::endl;
    std::cout << "f(x) = " << f(x);

    return 0;
}

