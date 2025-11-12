#include "dtf.h"
#include <cmath>

QVector<Harmonic> DTF(const QVector<Point>& points, int maxK, double T)
{
    QVector<Point> pts = points;
    if (pts.size() % 2 == 0) pts.pop_back();
    QVector<Harmonic> harmonics;
    int N = pts.size();
    if (N < 3 || N % 2 == 0) {
        qWarning("DTF: количество точек должно быть нечётным и >= 3.");
        return harmonics;
    }
    for (int k = 0; k < maxK; ++k) {
        auto cos_integrand = [=](const Point& p) {
            double angle = 2 * M_PI * k * p.x / T;
            return p.y * std::cos(angle);
        };
        auto sin_integrand = [=](const Point& p) {
            double angle = 2 * M_PI * k * p.x / T;
            return p.y * std::sin(angle);
        };
        double a_k = (2.0 / T) * adaptiveSimpsonFromPoints(pts, cos_integrand, 1e-6);
        double b_k = (2.0 / T) * adaptiveSimpsonFromPoints(pts, sin_integrand, 1e-6);
        harmonics.append({b_k, a_k});
    }
    return harmonics;
}
