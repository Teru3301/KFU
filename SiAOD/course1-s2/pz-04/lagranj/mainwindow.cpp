#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // === Интерфейс слева ===
    QLabel *pointCountLabel = new QLabel("Количество точек:", this);
    pointCountEdit = new QLineEdit(this);
    pointCountEdit->setMaximumWidth(100);

    QPushButton *updateButton = new QPushButton("Обновить", this);
    updateButton->setMaximumWidth(100);
    connect(updateButton, &QPushButton::clicked, this, &MainWindow::updateTable);

    QPushButton *calculateButton = new QPushButton("Рассчитать", this);
    calculateButton->setMaximumWidth(100);
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculate);

    table = new QTableWidget(this);
    table->verticalHeader()->setVisible(false);
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels(QStringList() << "x" << "y");
    table->setMaximumWidth(200);

    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->addWidget(pointCountLabel);
    leftLayout->addWidget(pointCountEdit);
    leftLayout->addWidget(updateButton);
    leftLayout->addWidget(calculateButton);
    leftLayout->addWidget(table);

    QWidget *leftWidget = new QWidget(this);
    leftWidget->setLayout(leftLayout);
    leftWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

    // === График справа ===
    this->customPlot = new QCustomPlot(this);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(leftWidget);
    mainLayout->addWidget(customPlot, 1); // растягивать график по ширине
}

MainWindow::~MainWindow() {}

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

        customPlot->clearGraphs();

    //  точки
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->setPen(QPen(Qt::transparent)); // линия не нужна
    customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::darkYellow), QBrush(Qt::darkYellow), 10)
        );

    lagranj(x, y);

    customPlot->addGraph();
    customPlot->graph(1)->setData(x, y);
    customPlot->graph(1)->setPen(QPen(Qt::blue));



    customPlot->xAxis->setRange(l_bord, r_bord);
    customPlot->yAxis->setRange(b_bord, u_bord);
    customPlot->replot();
}

void MainWindow::updateTable() {
    bool ok;
    int pointCount = pointCountEdit->text().toInt(&ok);
    if (ok && pointCount > 0) {
        table->setRowCount(pointCount);
    }
}

void MainWindow::calculate() {
    int rowCount = table->rowCount();
    QVector<double> x, y;

    for (int i = 0; i < rowCount; ++i) {
        bool okX, okY;
        QString xStr = table->item(i, 0) ? table->item(i, 0)->text() : "";
        QString yStr = table->item(i, 1) ? table->item(i, 1)->text() : "";

        double xi = xStr.toDouble(&okX);
        double yi = yStr.toDouble(&okY);

        if (okX && okY) {
            x.append(xi);
            y.append(yi);
        }
        else {
            QMessageBox::warning(this, "Ошибка", QString("Некорректные данные в строке %1").arg(i + 1));
            return;
        }
    }

    setupPlot(x, y);
}


void MainWindow::lagranj(QVector<double>& x, QVector<double>& y)
{
    if (x.size() != y.size() || x.isEmpty()) return;

    QVector<double> graphic_x;
    QVector<double> graphic_y;

    // Шаговая сетка по X для отрисовки полинома
    double x_min = *std::min_element(x.begin(), x.end());       //  координата начала графика
    double x_max = *std::max_element(x.begin(), x.end());       //  координаа конца графика
    int points = 200;                                           //  количество точек для построения гладкого графика

    //  Вычисление точек графика
    for (int i = 0; i < points; ++i) {                          //  создание точки
        double xi = x_min + (x_max - x_min) * i / (points - 1); //  точка х
        graphic_x.append(xi);                                   //  добавление в вектор иксов

        double yi = 0;                                          //  точка y
        for (int j = 0; j < x.size(); ++j) {
            double L = 1;                                       //  вычисление базисного полинома
            for (int k = 0; k < x.size(); ++k) {                //  
                if (k != j) {
                    L *= (xi - x[k]) / (x[j] - x[k]);           //  
                }
            }
            yi += y[j] * L;                                     //  вычисление Y
        }

        graphic_y.append(yi);                                   //  добавление в вектор игриков
    }

    x = graphic_x;
    y = graphic_y;
}






