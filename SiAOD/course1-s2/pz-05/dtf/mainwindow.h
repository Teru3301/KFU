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
    void setupPlot(QCustomPlot* plot, QVector<double> &x, QVector<double> &y);
    static double f(double x);
    QCustomPlot *originalPlot;  // график оригинальной функции
    QCustomPlot *restoredPlot;  // график восстановленной функции
    QCustomPlot *harmonicsPlot;

};

#endif // MAINWINDOW_H
