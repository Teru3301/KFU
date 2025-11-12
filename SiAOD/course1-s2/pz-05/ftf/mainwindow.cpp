
#include "mainwindow.h"
#include <cmath>
#include <algorithm>
#include <QElapsedTimer>
#include <QDebug>  // для вывода времени в консоль



double restored(const QVector<Harmonic>& harmonics, double x, double T)
{
    double y = harmonics[0].cos / 2.0;
    int N = harmonics.size();

    for (int k = 0; k < N; ++k)
    {
        double omega = 2 * M_PI * k / T;
        y += harmonics[k].cos * std::cos(omega * x) + harmonics[k].sin * std::sin(omega * x);
    }

    return y; // без деления
}


double MainWindow::f(double x)
{
    return x;
    //return fabs(x);
    //return abs(cos(x));
    //return sin(x);
    //return cos(x);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    originalPlot  = new QCustomPlot(this);
    restoredPlot  = new QCustomPlot(this);
    harmonicsPlot = new QCustomPlot(this);

    double a = -M_PI, b = M_PI;
    double T = b - a;
    int    N = 10;
    double step = T / (pow(2, 12));

    QVector<double> fx, fy;
    for (double xi = a; xi <= b; xi += step) {
        fx.append(xi);
        fy.append(f(xi));
    }
    setupPlot(originalPlot, fx, fy);
    originalPlot->graph(0)->setData(fx, fy);
    originalPlot->graph(0)->setPen(QPen(Qt::blue));
    originalPlot->xAxis->setLabel("x");
    originalPlot->yAxis->setLabel("f(x)");
    originalPlot->replot();

    QVector<Point> points;
    for (double xi = a; xi <= b; xi += step)
        points.append({xi, f(xi)});


    QElapsedTimer timer;
    timer.start();
    QVector<Harmonic> harmonics = FFT(points, N, T);
    qint64 elapsedMs = timer.elapsed();
    double seconds = elapsedMs / 1000.0;
    qDebug().noquote() << QString("Время выполнения: %1 с (%2 мс)")
                              .arg(QString::number(seconds, 'f', 3))
                              .arg(elapsedMs);

    QVector<double> rx, ry;
    for (double x = a; x <= b; x += step) {
        rx.append(x);
        ry.append(restored(harmonics, x, T));
    }
    setupPlot(restoredPlot, rx, ry);
    restoredPlot->graph(0)->setData(rx, ry);
    restoredPlot->graph(0)->setPen(QPen(Qt::red));
    restoredPlot->replot();

    QVector<double> kv, amp;
    for (int k = 0; k < harmonics.size(); ++k) {
        double A = std::hypot(harmonics[k].cos, harmonics[k].sin);
        kv.append(k);
        amp.append(A);
    }
    harmonicsPlot->addGraph();
    harmonicsPlot->graph(0)->setData(kv, amp);
    harmonicsPlot->graph(0)->setLineStyle(QCPGraph::lsImpulse);

    harmonicsPlot->xAxis->setRange(kv.first(), kv.last());
    double ampMax = *std::max_element(amp.constBegin(), amp.constEnd());
    harmonicsPlot->yAxis->setRange(0, ampMax * 1.1);

    harmonicsPlot->replot();

    QVBoxLayout *lyt = new QVBoxLayout(centralWidget);
    lyt->addWidget(originalPlot);
    lyt->addWidget(restoredPlot);
    lyt->addWidget(harmonicsPlot);
}

MainWindow::~MainWindow() {}

void MainWindow::setupPlot(QCustomPlot* plot,
                           const QVector<double>& x,
                           const QVector<double>& y)
{
    plot->clearGraphs();
    plot->addGraph();
    plot->xAxis->setRange(x.first(), x.last());
    double ymin = *std::min_element(y.constBegin(), y.constEnd());
    double ymax = *std::max_element(y.constBegin(), y.constEnd());
    double margin = (ymax - ymin) * 0.1;
    plot->yAxis->setRange(ymin - margin, ymax + margin);
    plot->graph(0)->setData(x,y);
    plot->replot();
}
