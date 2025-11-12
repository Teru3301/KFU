
#include <vector>
#include <iostream>
#include <iomanip>

//  m   -   строка
//  n   -   столбец
//  d   -   диагональ

inline void printmatr(std::vector<std::vector<double>> matr, std::vector<double> ans)
{
    int size = matr.size();
    for (int m = 0; m < size; m++)
    {
        for (int n = 0; n < size; n++)
            std::cout << std::setw(6) << std::setprecision(3) << matr[m][n];
        std::cout << " | " << ans[m] << std::endl;
    }
    std::cout << std::endl;
}

inline void refill_matrix(std::vector<std::vector<double>>& matr, std::vector<double>& ans, int& size)
{
    std::cout << "Нужно задать новые значения? +/-" << std::endl;
    std::string input_new; std::cin >> input_new;
    if (input_new == "+")
    {
        std::cout << "Размер матрицы: "; std::cin >> size;
        ans.resize(size);
        matr.resize(size);
        for (int m = 0; m < size; m++)
        {
            std::cout << "Строка-" << m+1 << ": ";
            matr[m].resize(size);
            for (int n = 0; n < size; n++)
                std::cin >> matr[m][n];
        }
        std::cout << "Ответы: ";
        for (int b = 0; b < size; b++)
            std::cin >> ans[b];
    }
    printmatr(matr, ans);
}

inline void totriangle(std::vector<std::vector<double>>& matr, std::vector<double>& ans)
{
    std::cout << "Приведение к треугольному виду:" << std::endl;

    for (int m = 0; m < matr.size() - 1; m++) {
        // Проверка на 0
        if (matr[m][m] == 0) {
            std::cout << "0 не может быть на главной диагонали!" << std::endl;
            return;
        }

        //  Приведение к треугольному виду
        for (int d = m + 1; d < matr.size(); d++) {           //  для всех последующих строк
            if (matr[d][m] != 0) {                     //  если элемент на диагонали не 0
                double div = matr[d][m] / matr[m][m];  //
                for (int n = m; n < matr.size(); n++) {       //  для всех столбцов строки
                    matr[d][n] -= div * matr[m][n];    //  вычесть
                }
                ans[d] -= div * ans[m];                //  корректировка столбца ответов b
            }
        }
    }
    printmatr(matr, ans);
}

inline void normalize_diagonal(std::vector<std::vector<double>>& matr, std::vector<double>& ans)
{
    std::cout << "Нормализация главной диагонали:" << std::endl;
    for (int m = 0; m < matr.size(); m++)
    {
        if (matr[m][m] != 1.0)
        {
            double div = 1.0 / matr[m][m];      //  значение на которое нужно умножить строку что бы диагональный элемент стал равен 1
            for (int n = 0; n < matr.size(); n++) matr[m][n] *= div;
            ans[m] *= div;
        }
    }
    printmatr(matr, ans);
}

inline void totriangle2 (std::vector<std::vector<double>>& matr, std::vector<double>& ans)
{
    std::cout << "Приведение к другой треугольной:" << std::endl;

    for (int d = matr.size() - 1; d >= 0; d--)  //  проход по диагонали от нижней строки к верхней
    {
        for (int m = d - 1; m >= 0; m--)        //  проход от нижней строки к верхней (самая жиняя строка выше текущего элемента диагонали)
        {
            double div = matr[m][d] * matr[d][d];
            for (int n = 0; n < matr.size(); n++)
            {
                matr[m][n] -= div * matr[d][n];
            }
            ans[m] -= ans[d] * div;
        }
    }
    printmatr(matr, ans);
}

// Функция для умножения матрицы на вектор
inline std::vector<double> mul_AV(std::vector<std::vector<double>>& A, std::vector<double>& x) {
    std::vector<double> result(A.size(), 0.0);
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            result[i] += A[i][j] * x[j];
        }
    }
    return result;
}

// Функция для умножения вектора на скаляр
inline std::vector<double> mul_VS(std::vector<double>& v, double scalar) {
    std::vector<double> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] * scalar;
    }
    return result;
}

// Функция для вычисления скалярного произведения двух векторов
inline double mul_VV(std::vector<double> v1, std::vector<double> v2) {
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Функция для сложения двух векторов
inline std::vector<double> sum_VV(std::vector<double> v1, std::vector<double> v2) {
    std::vector<double> result(v1.size());
    for (size_t i = 0; i < v1.size(); ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

// Функция для вычитания двух векторов
inline std::vector<double> sub_VV(std::vector<double> v1, std::vector<double> v2) {
    std::vector<double> result(v1.size());
    for (size_t i = 0; i < v1.size(); ++i) {
        result[i] = v1[i] - v2[i];
    }
    return result;
}

