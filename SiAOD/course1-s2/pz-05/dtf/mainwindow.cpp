#include "mainwindow.h"

struct Point {
    double x;
    double y;
    double z;
};

struct Harmonic {
    double sin;
    double cos;
};


double runge(double res1, double res2, double k, double p)
{
    return std::abs(res1 - res2) / (std::pow(k, p) - 1);
}

// Базовый метод Симпсона на отрезке
double simpson(const std::function<double(double)>& f, double a, double b, int n)
{
    n = n + (n % 2); // чётное число разбиений
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i <= n; ++i) {
        double x = a + i * h;
        double coeff = (i == 0 || i == n) ? 1 : (i % 2 == 0 ? 2 : 4);
        sum += coeff * f(x);
    }

    return (h / 3.0) * sum;
}

// Адаптивный метод Симпсона
double adaptiveSimpson(const std::function<double(double)>& f, double a, double b, int& n, double max_error)
{
    const int k = 2;
    double res1 = simpson(f, a, b, n);
    double res2 = simpson(f, a, b, n * k);

    if (runge(res1, res2, k, 4) < max_error)
        return res2;

    double mid = (a + b) / 2.0;
    return adaptiveSimpson(f, a, mid, n, max_error) + adaptiveSimpson(f, mid, b, n, max_error);
}


double adaptiveSimpsonFromPoints(const QVector<Point>& points, std::function<double(const Point&)> func, double max_error)
{
    int N = points.size();
    if (N < 2) {
        qWarning("Недостаточно точек.");
        return 0.0;
    }

    double result = 0.0;
    int base_n = 4;

    for (int i = 0; i < N - 1; ++i) {
        double a = points[i].x;
        double b = points[i + 1].x;

        // Локальная функция f(x), интерполирующая значение y по данным точкам
        auto f = [&](double x) -> double {
            // Интерполяция линейная
            double t = (x - points[i].x) / (points[i + 1].x - points[i].x);
            double y = (1 - t) * points[i].y + t * points[i + 1].y;
            Point p = {x, y};
            return func(p);
        };

        result += adaptiveSimpson(f, a, b, base_n, max_error);
    }

    return result;
}



QVector<Harmonic> DTF(const QVector<Point>& points, int maxK, double T)
{
    QVector<Harmonic> harmonics;
    int N = points.size();
    if (N < 3 || N % 2 == 0) {
        qWarning("DTF: количество точек должно быть нечётным и >= 3.");
        return harmonics;
    }

    for (int k = 0; k < maxK; ++k)
    {
        auto cos_integrand = [=](const Point& p) {
            double angle = 2 * M_PI * k * p.x / T;
            return p.y * std::cos(angle);
        };

        auto sin_integrand = [=](const Point& p) {
            double angle = 2 * M_PI * k * p.x / T;
            return p.y * std::sin(angle);
        };

        double a_k = (2.0 / T) * adaptiveSimpsonFromPoints(points, cos_integrand, 1e-6);
        double b_k = (2.0 / T) * adaptiveSimpsonFromPoints(points, sin_integrand, 1e-6);


        harmonics.append({b_k, a_k}); // sin = b_k, cos = a_k
    }

    return harmonics;
}



double restored(const QVector<Harmonic>& harmonics, double x, double T)
{
    double y = 0.0;
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
    //return (int(x) % 2 ? 1.0 : 0);
    //return fabs(x);
    //return cos(x * 3) + 2;
    return sin(x);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создаём два отдельных графика
    this->originalPlot = new QCustomPlot(this);
    this->restoredPlot = new QCustomPlot(this);

    this->harmonicsPlot = new QCustomPlot(this);


    double a = -M_PI;
    double b = M_PI;
    double T = b - a;
    double N = 100;
    double step = 0.001;

    // Создаём точки для оригинальной функции
    QVector<double> fx, fy;
    for (double xi = a; xi <= b; xi += step)
    {
        fx.append(xi);
        fy.append(f(xi));
    }
    setupPlot(originalPlot, fx, fy);  // оригинальная функция



    // Заполняем график оригинальной функции
    originalPlot->graph(0)->setData(fx, fy);
    originalPlot->graph(0)->setPen(QPen(Qt::blue));  // цвет линии
    originalPlot->xAxis->setLabel("x");
    originalPlot->yAxis->setLabel("f(x)");
    originalPlot->replot();

    // Получаем гармоники    
    QVector<Point> points;
    for (double xi = a; xi <= b; xi += step)
    {
        points.append({xi, f(xi)});
    }
    if (points.size() % 2 == 0)
    {
        double lastX = points.last().x + step;
        points.append({lastX, f(lastX)});
    }

    // Берём ограниченное число гармоник
    QVector<Harmonic> harmonics = DTF(points, N, T);


    // Строим восстановленную функцию по Фурье
    QVector<double> rx, ry;
    for (double x = a; x <= b; x += step)
    {
        rx.append(x);
        ry.append(restored(harmonics, x, T));  // Восстановление функции
    }
    setupPlot(restoredPlot, rx, ry);  // восстановленная функция

    // Добавим график восстановленной функции
    restoredPlot->graph(0)->setData(rx, ry);
    restoredPlot->graph(0)->setPen(QPen(Qt::red));  // Цвет графика Фурье
    restoredPlot->xAxis->setLabel("x");
    restoredPlot->yAxis->setLabel("f_восстановл(x)");
    restoredPlot->xAxis->setRange(rx.first(), rx.last());
    restoredPlot->yAxis->setRange(*std::min_element(ry.begin(), ry.end()),
                                  *std::max_element(ry.begin(), ry.end()));
    restoredPlot->replot();



    QVector<double> kValues, amplitudes;
    for (int k = 0; k < harmonics.size(); ++k) {
        double a_k = harmonics[k].cos;
        double b_k = harmonics[k].sin;
        double A = sqrt(a_k * a_k + b_k * b_k);
        kValues.append(k);
        amplitudes.append(A);
    }

    // Настраиваем график спектра гармоник
    harmonicsPlot->addGraph();
    harmonicsPlot->graph(0)->setData(kValues, amplitudes);
    harmonicsPlot->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    harmonicsPlot->graph(0)->setPen(QPen(Qt::darkGreen, 2));
    harmonicsPlot->xAxis->setLabel("Номер гармоники (k)");
    harmonicsPlot->yAxis->setLabel("Амплитуда");
    harmonicsPlot->xAxis->setRange(-0.5, harmonics.size() - 0.5);
    harmonicsPlot->yAxis->setRange(0, *std::max_element(amplitudes.begin(), amplitudes.end()) * 1.1);
    harmonicsPlot->replot();





    // Layout для размещения графиков вертикально
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(originalPlot);
    mainLayout->addWidget(restoredPlot);

    mainLayout->addWidget(harmonicsPlot);
}





MainWindow::~MainWindow() {}

void MainWindow::setupPlot(QCustomPlot* plot, QVector<double> &x, QVector<double> &y)
{
    plot->clearGraphs();
    plot->addGraph();


    double x_min = x.isEmpty() ? -10 : *std::min_element(x.begin(), x.end());
    double x_max = x.isEmpty() ?  10 : *std::max_element(x.begin(), x.end());
    double y_min = y.isEmpty() ? -1 : *std::min_element(y.begin(), y.end());
    double y_max = y.isEmpty() ?  1 : *std::max_element(y.begin(), y.end());

    double x_margin = (x_max - x_min) * 0.1;
    double y_margin = (y_max - y_min) * 0.1;

    if (x_margin == 0) x_margin = 1.0;
    if (y_margin == 0) y_margin = 1.0;

    //plot->xAxis->setRange(x_min - x_margin, x_max + x_margin);
    plot->yAxis->setRange(y_min - y_margin, y_max + y_margin);


    plot->xAxis->setRange(x[0], x[x.size() - 1]);
    //plot->yAxis->setRange(y[0], y[y.size() - 1]);

    plot->replot();
}

