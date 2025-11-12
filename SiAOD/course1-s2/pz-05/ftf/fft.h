#pragma once
#include <QVector>
#include <complex>
#include "simpson.h"

QVector<Harmonic> FFT(const QVector<Point>& points, int maxK, double T);
