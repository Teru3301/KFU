#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    this->customPlot = new QCustomPlot(this);

    QVector<double> x, y;
    double a = 1.0;
    double b = 1.2;
    double h = 0.04;
    QVector<double> dydx;
    calc_points(f, a, b, h, x, y, dydx);

    setupPlot(x, y, dydx);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(customPlot, 1); // растягивать график по ширине
}

MainWindow::~MainWindow() {}

double MainWindow::f(double x)
{
    //return pow(2.718, x);
    return sin(x);
}

void MainWindow::calc_points(double (*f)(double), double a, double b, double h, QVector<double>& x, QVector<double>& y, QVector<double>& dydx)
{
    x.clear();
    y.clear();
    dydx.clear();
    a -= h;

    while (a <= b)
    {
        a += h;
        x.append(a);
        y.append(f(a));
        dydx.append(cos(a)); // если f(x) = sin(x), то f'(x) = cos(x)
    }
}


double S(double x, double x0, double a, double b, double c, double d)
{
    return a + b*(x - x0) + c * pow(x - x0, 2.0) + d * pow(x - x0, 3.0);
}


double hermite(double t, double p0, double p1, double m0, double m1)
{
    double h00 = 2*t*t*t - 3*t*t + 1;
    double h10 = t*t*t - 2*t*t + t;
    double h01 = -2*t*t*t + 3*t*t;
    double h11 = t*t*t - t*t;

    return h00*p0 + h10*m0 + h01*p1 + h11*m1;
}


void MainWindow::hermite_spline(QVector<double>& x, QVector<double>& y, QVector<double>& dydx)
{
    QVector<double> new_x, new_y;
    int steps = 20;

    for (int i = 0; i < x.size() - 1; i++)
    {
        double x0 = x[i];
        double x1 = x[i + 1];
        double y0 = y[i];
        double y1 = y[i + 1];
        double m0 = dydx[i] * (x1 - x0); // масштабируем производные
        double m1 = dydx[i + 1] * (x1 - x0);

        for (int j = 0; j <= steps; j++)
        {
            double t = double(j) / steps;
            double xi = x0 + t * (x1 - x0);
            double yi = hermite(t, y0, y1, m0, m1);
            new_x.append(xi);
            new_y.append(yi);
        }
    }

    x = new_x;
    y = new_y;
}


void MainWindow::setupPlot(QVector<double> x, QVector<double> y, QVector<double>& dydx){

    //  Просто красивость

    double l_bord;  //  левая граница графика
    double r_bord;  //  правая граница графика
    double u_bord;  //  верхняя граница графика
    double b_bord;  //  нижняя граница графика
    // Нахождение минимумов и максимумов
    double x_min = *std::min_element(x.begin(), x.end());
    double x_max = *std::max_element(x.begin(), x.end());
    double y_min = *std::min_element(y.begin(), y.end());
    double y_max = *std::max_element(y.begin(), y.end());
    // Добавление 10% от диапазона
    double x_margin = (x_max - x_min) * 0.5;
    double y_margin = (y_max - y_min) * 0.5;
    // Обработка случая, если все точки одинаковые (диапазон 0)
    if (x_margin == 0) x_margin = 1.0;
    if (y_margin == 0) y_margin = 1.0;

    l_bord = x_min - x_margin;
    r_bord = x_max + x_margin;
    b_bord = y_min - y_margin;
    u_bord = y_max + y_margin;


    //  Заполнение графика

    customPlot->clearGraphs();                              //  очистка

    //  точки
    customPlot->addGraph();                                 //  график для точек
    customPlot->graph(0)->setData(x, y);                    //  заполнение
    customPlot->graph(0)->setPen(QPen(Qt::transparent));    // отключение линии
    customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);   // отключение линии
    customPlot->graph(0)->setScatterStyle(                  // цвет точек
        QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::darkYellow), QBrush(Qt::darkYellow), 10)
        );

    //  сплайн
    customPlot->addGraph();
    hermite_spline(x, y, dydx);
    customPlot->graph(1)->setData(x, y);
    customPlot->graph(1)->setPen(QPen(Qt::transparent));    // отключение линии
    customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);   // отключение линии
    customPlot->graph(1)->setScatterStyle(                  // цвет точек
        QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::darkYellow), QBrush(Qt::darkYellow), 3)
        );
    //customPlot->graph(1)->setPen(QPen(Qt::blue));   //  цвет линии

    customPlot->xAxis->setRange(l_bord, r_bord);
    customPlot->yAxis->setRange(b_bord, u_bord);
    customPlot->replot();
}





