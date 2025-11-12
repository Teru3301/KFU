#include <iostream>
#include <cmath>
#include <iomanip>

int total = 0;
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
    total++;
    return sum * h / 3.0;
}


double runge(double res1, double res2, double k, double p)
{
    return std::abs(res1 - res2) / (std::pow(k, p) - 1);
}


double adaptive(double a, double b, int &n, double max_error)
{
    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    double k = 2;
    double res1 = simpson(a, b, n);
    double res2 = simpson(a, b, n*k);

    total--;
    if ( std::abs(runge(res1, res2, k, 4)) < max_error ) return res1;
    total--;
    return adaptive(a, a + (b - a) / 2.0, n, max_error) + adaptive(a + (b - a) / 2.0, b, n, max_error);
}


int main() {
    double a = 0.0;             // Начало отрезка
    double b = 1.5;             // Конец отрезка
    int n = 5;                  // Количество разбиений
    double max_error = 0.0001;  // допустимая погрешность

    double res = adaptive(a, b, n, max_error);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "[" << a << ", " << b << "] кол-во шагов " << std::setw(3) << n*total << std::endl;
    std::cout << std::setprecision(34);
    std::cout << "Макс. погрешность: " << max_error << std::endl;
    std::cout << "Ответ            : " << res << std::endl;

    return 0;
}
