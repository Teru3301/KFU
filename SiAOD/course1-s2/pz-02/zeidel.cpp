//  Метод Гаусса-Зейделя (простых итераций)
//
//  каждая переменная выражается через вседругие постепенно уточняя своё значение
//      x + y + z = b   =>  x = b - y - z
//      x + y + z = b   =>  y = b - x - z
//      x + y + z = b   =>  z = b - x - y
//
//  затем в место неизвестных на первом шаге подставляются нули
//      x1 = b - 0  - 0
//  далее найденное значенные значения подставляются в последующие уравнения
//      y1 = b - x1 - 0
//      z1 = b - x1 - y1
//
//  в последующих уравнения сразу будут подставляться обновлёные значения неизвестных
//      x2 = b - y1 - z1
//      y2 = b - x2 - z1
//      z2 = b - x2 - y2
//
//      x3 = b - y2 - z2
//      y3 = b - x3 - z2
//      z3 = b - x3 - y3
//
//  процесс продолжается до тех пор пока изменение переменных не станет меньше заданного эпсилон


#include <cmath>
#include "matr_functions.h"


void zeidel(std::vector<std::vector<double>>& matr, std::vector<double>& b, std::vector<double>& x, double epsilon)
{
    std::vector<double> prev_x;     //  предыдущее приближение ответов (нужно для проверки достигнутой точности)

    for (size_t iteration = 1; iteration < 1000; iteration++)
    {
        prev_x = x;                             //  сохранение текущих значений
        for (int m = 0; m < matr.size(); m++)   //  проход по всем уравнениям
        {
            x[m] = b[m];
            for (int n = 0; n < m; n++)
                x[m] -= matr[m][n] * x[n];
            for (int n = m + 1; n < matr.size(); n++)
                x[m] -= matr[m][n] * prev_x[n];

            x[m] /= matr[m][m];
        }

        //  проверка точности
        //  выбирается максимальная разность между текущим и предыдущим ответом
        double diff = 0.0;
        for (int i = 0; i < x.size(); i++)
            if (std::fabs(x[i] - prev_x[i]) > diff)
                diff = std::fabs(x[i] - prev_x[i]);
        if (diff < epsilon)
        {
            std::cout << "Ответ получен на " << iteration << " итерации." << std::endl;
            return;
        }
    }
    std::cout << "Заданная точность не была достигнута за 1000 итераций." << std::endl;
}


int main()
{
    int size = 3;                           //  размер квадратной матрицы
    std::vector<std::vector<double>> matr;  //  матрица
    std::vector<double> b = {-3, -1, 1};  //  свободные члены

    matr = {            //  предзаполнение матрицы значениями из задания
            {5, -1, 1},
            {-1, 3, 1},
            {2, 1, 4}
        };
    std::vector<double> x = {0, 0, 0};      //  последние значения неизвестных (на первом шаге нули, дальше они уточняются)

    refill_matrix(matr, b, size);

    zeidel(matr, b, x, 0.000001);
    std::cout << std::endl << "Ответ: ";
    for (auto a : x) std::cout << std::fixed << a << "  ";
    std::cout << std::endl;

    return 0;
}


