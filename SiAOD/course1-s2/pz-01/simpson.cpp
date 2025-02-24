#include <iostream>
#include <cmath>
#include <iomanip>


double func (double x)
{
    return x * std::pow(std::exp(1), 0.4 * x) / std::pow(1 + 0.4 * x, 2.0);
}


double simpson(double a, double b, int n) {
    n = n + (n % 2);
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i <= n; ++i) {
        double x = a + i * h;
        if (i == 0 || i == n) {     // Первый и последний элементы берутся с коэффициентом 1
            sum += func(x);
        } else {                    // Для четных 2 для нечетных 4 
            sum += (i % 2 ? 4 : 2) * func(x);
        }
    }

    return sum * h / 3.0;
}


double runge(double res1, double res2, double k, double p)
{
    return std::abs(res1 - res2) / (std::pow(2, p) - 1);
}


int main() {
    double a = 0.3;  // Начало отрезка
    double b = 1.5;  // Конец отрезка
    int n = 5;   // Количество разбиений
    double k = 2;

    double res1 = simpson(a, b, n);
    double res2 = simpson(a, b, n*k);
    std::cout << std::setprecision(8) << std::fixed;
    std::cout << "[" << a << ", " << b << "] кол-во шагов " << std::setw(5) 
        << n << ": " << res1 << std::endl;
    std::cout << "[" << a << ", " << b << "] кол-во шагов " << std::setw(5)
        << int(n * k) << ": " << res2 << std::endl;

    std::cout << "Погрешность по рунге: " << runge(res1, res2, k, 4) << std::endl;


    return 0;
}
