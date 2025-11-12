//  Метод Флетчера-Ривса
//
//  создаётся начальное приближение (вектор нулей)  x
//  вычисляется начальный градиент                  g
//  вычисляется антиградиент                        p = g * -1
//
//  вычисляется шаг приближения
//  вычисляются новые значения неизвестных как сумма старых значений и произведение шага на антиградиент
//  вычисляется новый градиент. разность произведения матрицы на новые значения неизвестных и свободных членов b
//  можно проверить была ли достигнута заданная точность g*g < lambda
//  если заданная точность не была достигнута - обновляем: антиградиент, значения x и градиент


#include <cmath>

#include "matr_functions.h"


std::vector<double> fletcher(std::vector<std::vector<double>> matr, std::vector<double> b, double lambda)
{
    std::vector<double> x = std::vector<double>(b.size(), 0);   //  начальное значение неизвестных
    std::vector<double> g = sub_VV(mul_AV(matr, x), b);         //  градиент            g = A * x - b
    std::vector<double> p = mul_VS(g, -1);                      //  антиградиент        p0 = -g0

    for (int iteration = 0; iteration < 1000; iteration++)
    {
        double alpha = mul_VV(g, g) / mul_VV(p, mul_AV(matr, p));       //  шаг приближения
        std::vector<double> x_new = sum_VV(x, mul_VS(p, alpha));        //  новые значения x    x_new = x + alpha * p
        std::vector<double> g_new = sub_VV(mul_AV(matr, x_new), b);     //  новый градиент      g_new = A * x_new - b

        if (std::sqrt(mul_VV(g_new, g_new)) < lambda)   //  проверка достижения заданной точности
        {
            std::cout << "Ответ получен на " << iteration + 1 << " итерации." << std::endl;
            return x_new;                               //  решение найдено
        }

        //  подготовка к следующей итерации
        p = sum_VV(mul_VS(g_new, -1),                           //  обновление антиградиента
            mul_VS(p, mul_VV(g_new, g_new) / mul_VV(g, g)));
        x = x_new;                                              //  обновление значения неизвестных
        g = g_new;                                              //  обновление градиента
    }
    return x;
}




int main ()
{
    int size = 3;                           //  размер квадратной матрицы
    std::vector<std::vector<double>> matr;  //  матрица
    std::vector<double> b = {-3, -1, 1};    //  свободные члены

    matr = {                                //  предзаполнение матрицы значениями из задания
            {5, -1, 20},
            {-1, 3, 1},
            {20, 1, 4}
        };

    refill_matrix(matr, b, size);         //  заполнение матрицы новыми значениями (опционально)

    std::vector<double> ans = fletcher(matr, b, 0.001);

    std::cout << "Ответ: ";
    for (auto a : ans) std::cout << a << " ";


    return 0;
}
