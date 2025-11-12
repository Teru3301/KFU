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
    void setupPlot(QVector<double> x, QVector<double> y);
    void lagranj(QVector<double>& x, QVector<double>& y);

    QLineEdit *pointCountEdit;
    QTableWidget *table;


private slots:
    void updateTable();
    void calculate();

};

#endif // MAINWINDOW_H
