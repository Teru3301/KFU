#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>


double func(double x)
{
    return x * std::pow(std::exp(1), 0.4 * x) / std::pow(1 + 0.4 * x, 2.0);
}


double montecarlo (double a, double b, int n)
{
    double sum = 0;
    for (int i = 0; i <= n; i++)
    {
        double x = a + double(rand()) / RAND_MAX * (b - a);
        sum += std::fabs(func(x));
    }

    return (b - a) * (sum / double(n));
}


int main ()
{
    double a = 0.0;         // начало
    double b = 1.5;         // конец
    int n = 1000;            // количество забрасываемых точек за один заброс
    double e = 0.0001;      // допустимая погрешность
    double error = 1000000; // текущее значение погрешности
    int k = 5;              // количество забросов точек

    std::vector<double> res;
    
    while (error > e)
    {
        n *= 2;

        res.clear();
        for (int i = 0; i < k; i++)
            res.push_back(montecarlo(a, b, n));

        double squares = 0;
        double sum = 0;
        for (int i = 0; i < k; i++)
        {
            squares += std::pow(res[i], 2.0);
            sum += res[i];
        }
        squares /= double(k);
        sum /= double(k);

        error = std::sqrt(std::fabs( squares - pow(sum, 2.0) ));
        std::cout << error << std::endl;
    }

    std::cout << std::fixed << std::setprecision(8);
    std::cout << "[" << a << ", " << b << "] точек " << std::setw(12)
        << int(n) << ": " << res[0] << std::endl;
    std::cout << "Погрешность: " << error << std::endl;

    return 0;
}
