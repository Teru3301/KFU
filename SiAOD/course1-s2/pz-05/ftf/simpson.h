#pragma once
#include <functional>
#include <QVector>
#include <cmath>
#include <QDebug>

struct Point {
    double x;
    double y;
    double z;
};

struct Harmonic {
    double sin;
    double cos;
};

// Compute Runge's error estimate
double runge(double res1, double res2, double k, double p);

// Basic Simpson method on interval [a,b] with n subdivisions (n even)
double simpson(const std::function<double(double)>& f, double a, double b, int n);

// Adaptive Simpson with error control
double adaptiveSimpson(const std::function<double(double)>& f,
                       double a, double b,
                       int& n,
                       double max_error);

// Adaptive Simpson for discrete Point samples
double adaptiveSimpsonFromPoints(const QVector<Point>& points,
                                 std::function<double(const Point&)> func,
                                 double max_error);
