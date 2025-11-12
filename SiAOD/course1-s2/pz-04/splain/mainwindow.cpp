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
    calc_points(f, a, b, h, x, y);

    setupPlot(x, y);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(customPlot, 1); // растягивать график по ширине
}

MainWindow::~MainWindow() {}

double MainWindow::f(double x)
{
    return sin(x);
}

void MainWindow::calc_points(double (*f)(double), double a, double b, double h, QVector<double>& x, QVector<double>& y)
{
    x.clear();
    y.clear();
    a -= h;

    while(a <= b)
    {
        a += h;
        x.append(a);
        y.append(f(x.last()));#include "mainwindow.h"

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
    calc_points(f, a, b, h, x, y);

    setupPlot(x, y);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(customPlot, 1); // растягивать график по ширине
}

MainWindow::~MainWindow() {}

double MainWindow::f(double x)
{
    return sin(x);
}

void MainWindow::calc_points(double (*f)(double), double a, double b, double h, QVector<double>& x, QVector<double>& y)
{
    x.clear();
    y.clear();
    a -= h;

    while(a <= b)
    {
        a += h;
        x.append(a);
        y.append(f(x.last()));
    }
}

double S(double x, double x0, double a, double b, double c, double d)
{
    return a + b*(x - x0) + c * pow(x - x0, 2.0) + d * pow(x - x0, 3.0);
}

void MainWindow::splain(QVector<double>& x, QVector<double>& y)
{
    size_t n = x.size();

    QVector<double> a(n);           // Коэффициенты a_i, равные значениям функции в узлах (a_i = y_i)
    QVector<double> b(n - 1);       // Коэффициенты b_i — линейные коэффициенты для каждого отрезка сплайна
    QVector<double> c(n);           // Коэффициенты c_i — квадратичные коэффициенты сплайна (в том числе внутренние и граничные)
    QVector<double> d(n - 1);       // Коэффициенты d_i — кубические коэффициенты для каждого отрезка

    QVector<double> h(n - 1);       // Шаги между соседними узлами: h_i = x[i+1] - x[i]
    QVector<double> alpha(n - 1);   // Правая часть системы уравнений для вычисления c_i (в методе прогонки)

    QVector<double> l(n);           // Вспомогательный вектор для метода прогонки (диагональные элементы)
    QVector<double> mu(n);          // Вспомогательный вектор (пропорции между элементами при прямом ходе)
    QVector<double> z(n);           // Временное хранилище для правых частей при прогонке (решение системы)


    // Шаг 1: коэффициенты a и h
    for (size_t i = 0; i < n; i++)
        a[i] = y[i];

    for (size_t i = 0; i < n - 1; i++)
        h[i] = x[i + 1] - x[i];

    // Шаг 2: система уравнений для c
    for (size_t i = 1; i < n - 1; i++)
        alpha[i] = (3.0 / h[i]) * (a[i + 1] - a[i]) - (3.0 / h[i - 1]) * (a[i] - a[i - 1]);

    // Шаг 3: прямой ход метода прогонки
    l[0] = 1.0;
    mu[0] = 0.0;
    z[0] = 0.0;

    for (size_t i = 1; i < n - 1; i++) {
        l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n - 1] = 1.0;
    z[n - 1] = 0.0;
    c[n - 1] = 0.0;

    // Шаг 4: обратный ход метода прогонки
    for (int j = n - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0;
        d[j] = (c[j + 1] - c[j]) / (3.0 * h[j]);
    }

    // Шаг 5: генерация новых точек по сплайну
    QVector<double> new_x;
    QVector<double> new_y;
    int steps = 20;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= steps; j++) {
            double dx = (x[i + 1] - x[i]) / steps;
            double xi = x[i] + j * dx;
            double yi = S(xi, x[i], a[i], b[i], c[i], d[i]);
            new_x.append(xi);
            new_y.append(yi);
        }
    }

    x = new_x;
    y = new_y;
}

void MainWindow::setupPlot(QVector<double> x, QVector<double> y){

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


    }
}

double S(double x, double x0, double a, double b, double c, double d)
{
    return a + b*(x - x0) + c * pow(x - x0, 2.0) + d * pow(x - x0, 3.0);
}

void MainWindow::splain(QVector<double>& x, QVector<double>& y)
{
    size_t n = x.size();

    QVector<double> a(n);           // Коэффициенты a_i, равные значениям функции в узлах (a_i = y_i)
    QVector<double> b(n - 1);       // Коэффициенты b_i — линейные коэффициенты для каждого отрезка сплайна
    QVector<double> c(n);           // Коэффициенты c_i — квадратичные коэффициенты сплайна (в том числе внутренние и граничные)
    QVector<double> d(n - 1);       // Коэффициенты d_i — кубические коэффициенты для каждого отрезка

    QVector<double> h(n - 1);       // Шаги между соседними узлами: h_i = x[i+1] - x[i]
    QVector<double> alpha(n - 1);   // Правая часть системы уравнений для вычисления c_i (в методе прогонки)

    QVector<double> l(n);           // Вспомогательный вектор для метода прогонки (диагональные элементы)
    QVector<double> mu(n);          // Вспомогательный вектор (пропорции между элементами при прямом ходе)
    QVector<double> z(n);           // Временное хранилище для правых частей при прогонке (решение системы)


    // Шаг 1: коэффициенты a и h
    for (size_t i = 0; i < n; i++)
        a[i] = y[i];

    for (size_t i = 0; i < n - 1; i++)
        h[i] = x[i + 1] - x[i];

    // Шаг 2: система уравнений для c
    for (size_t i = 1; i < n - 1; i++)
        alpha[i] = (3.0 / h[i]) * (a[i + 1] - a[i]) - (3.0 / h[i - 1]) * (a[i] - a[i - 1]);

    // Шаг 3: прямой ход метода прогонки
    l[0] = 1.0;
    mu[0] = 0.0;
    z[0] = 0.0;

    for (size_t i = 1; i < n - 1; i++) {
        l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n - 1] = 1.0;
    z[n - 1] = 0.0;
    c[n - 1] = 0.0;

    // Шаг 4: обратный ход метода прогонки
    for (int j = n - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0;
        d[j] = (c[j + 1] - c[j]) / (3.0 * h[j]);
    }

    // Шаг 5: генерация новых точек по сплайну
    QVector<double> new_x;
    QVector<double> new_y;
    int steps = 20;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= steps; j++) {
            double dx = (x[i + 1] - x[i]) / steps;
            double xi = x[i] + j * dx;
            double yi = S(xi, x[i], a[i], b[i], c[i], d[i]);
            new_x.append(xi);
            new_y.append(yi);
        }
    }

    x = new_x;
    y = new_y;
}

void MainWindow::setupPlot(QVector<double> x, QVector<double> y){

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
    splain(x, y);
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





