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

#include "simpson.h"
#include "dtf.h"
#include "fft.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    double f(double x);
    void setupPlot(QCustomPlot* plot, const QVector<double>& x, const QVector<double>& y);
    QCustomPlot *originalPlot;
    QCustomPlot *restoredPlot;
    QCustomPlot *harmonicsPlot;
};

#endif // MAINWINDOW_H

