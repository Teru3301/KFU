#include "fft.h"
#include <cmath>

namespace {
    void fftRecursive(QVector<std::complex<double>>& samples) {
        int N = samples.size();
        if (N <= 1) return;
        QVector<std::complex<double>> even(N/2), odd(N/2);
        for (int i = 0; i < N/2; ++i) {
            even[i] = samples[2*i];
            odd[i]  = samples[2*i + 1];
        }
        fftRecursive(even);
        fftRecursive(odd);
        double angle = -2 * M_PI / N;
        for (int k = 0; k < N/2; ++k) {
            std::complex<double> mul = std::polar(1.0, angle * k);
            samples[k]         = even[k] + mul * odd[k];
            samples[k+N/2]     = even[k] - mul * odd[k];
        }
    }
}

QVector<Harmonic> FFT(const QVector<Point>& points, int maxK, double T)
{
    int N = points.size();
    if ((N & (N - 1)) != 0) {
        qWarning("FFT: количество точек должно быть степенью двойки. (%d).", N);
        return {};
    }
    QVector<std::complex<double>> samples(N);
    for (int i = 0; i < N; ++i)
        samples[i] = std::complex<double>(points[i].y, 0.0);
    fftRecursive(samples);
    QVector<Harmonic> harmonics;
    double scale = 2.0 / N;
    for (int k = 0; k < maxK && k <= N/2; ++k) {
        auto c = samples[k];
        double a_k = -c.real() * scale;
        double b_k =  c.imag() * scale;
        if (k == 0 || k == N/2) {
            a_k /= 2; b_k /= 2;
        }
        harmonics.append({b_k, a_k});
    }
    return harmonics;
}
