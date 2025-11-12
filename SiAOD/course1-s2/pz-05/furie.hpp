


#include <vector>
#include <cmath>



const double PI = 3.14;

struct Point {
    double x;
    double y;
};

struct Harmonic {
    double sin;
    double cos;
};



//  Дискретное преобразование Фурье
std::vector<Harmonic> DTF(const std::vector<Point>& point)
{
    std::vector<Harmonic> harmonics;    //  гармоники
    size_t N = point.size();            //  количество гармоник


    for (int i = 0; i < N; i++)
    {
        Harmonic new_harmonic;
        new_harmonic.sin = 0;
        new_harmonic.cos = 0;
        for (int n = 0; n < N; n++)
        {
            double L = 2 * PI * i * n / N;
            new_harmonic.cos += point[n].y * cos(L);
            new_harmonic.sin += point[n].y * sin(L);
        }
        harmonics.push_back(new_harmonic);
    }


    return harmonics;
}



double restored(const std::vector<Harmonic>& harmonic, double x, double T)
{
    double y = 0.0;
    size_t N = harmonic.size();

    for (size_t k = 0; k < N; ++k)
    {
        double omega = 2 * PI * k / T;
        y += harmonic[k].cos * std::cos(omega * x) + harmonic[k].sin * std::sin(omega * x);
    }

    return y / double(N); // Усреднение — как в классическом обратном DFT
}
