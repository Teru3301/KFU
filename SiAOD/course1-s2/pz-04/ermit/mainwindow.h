#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include "qcustomplot.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QCustomPlot *customPlot;
    void setupPlot(QVector<double> x, QVector<double> y, QVector<double>& dydx);
    static double f(double x);
    void calc_points(double (*f)(double), double a, double b, double h, QVector<double>& x, QVector<double>& y, QVector<double>& dydx);
    void splain(QVector<double>& x, QVector<double>& y);
    void hermite_spline(QVector<double>& x, QVector<double>& y, QVector<double>& dydx);
};

#endif // MAINWINDOW_H
