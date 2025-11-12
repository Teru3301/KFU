#pragma once
#include <QVector>
#include "simpson.h"

QVector<Harmonic> DTF(const QVector<Point>& points, int maxK, double T);
