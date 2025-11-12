#include "simpson.h"

double runge(double res1, double res2, double k, double p)
{
    return std::abs(res1 - res2) / (std::pow(k, p) - 1.0);
}

double simpson(const std::function<double(double)>& f, double a, double b, int n)
{
    n = n + (n % 2);
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i <= n; ++i) {
        double x = a + i * h;
        double coeff = (i == 0 || i == n) ? 1 : (i % 2 == 0 ? 2 : 4);
        sum += coeff * f(x);
    }
    return (h / 3.0) * sum;
}

double adaptiveSimpson(const std::function<double(double)>& f,
                       double a, double b,
                       int& n,
                       double max_error)
{
    const int k = 2;
    double res1 = simpson(f, a, b, n);
    double res2 = simpson(f, a, b, n * k);
    if (runge(res1, res2, k, 4) < max_error)
        return res2;
    double mid = (a + b) / 2.0;
    return adaptiveSimpson(f, a, mid, n, max_error) +
           adaptiveSimpson(f, mid, b, n, max_error);
}

double adaptiveSimpsonFromPoints(const QVector<Point>& points,
                                 std::function<double(const Point&)> func,
                                 double max_error)
{
    int N = points.size();
    if (N < 2) {
        qWarning("Недостаточно точек.");
        return 0.0;
    }
    double result = 0.0;
    int base_n = 4;
    for (int i = 0; i < N - 1; ++i) {
        double a = points[i].x;
        double b = points[i+1].x;
        auto f = [&](double x) -> double {
            double t = (x - points[i].x) / (points[i+1].x - points[i].x);
            double y = (1 - t) * points[i].y + t * points[i+1].y;
            Point p = {x, y};
            return func(p);
        };
        result += adaptiveSimpson(f, a, b, base_n, max_error);
    }
    return result;
}
