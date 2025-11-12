// Метод Гаусса
//
//
//
//
//
//
//
//
//


#include "matr_functions.h"


std::vector<double> getanswers(const std::vector<std::vector<double>>& matr, const std::vector<double>& b)
{
    int size = matr.size();
    std::vector<double> variables(size);

    for (int m = size - 1; m >= 0; m--) {       //  от нижней строки к верхней
        double sum = b[m];
        for (int n = m + 1; n < size; n++) {    //  для каждого элемента текущей строки
            sum -= matr[m][n] * variables[n];   //  для m-нойнеизвестной вычисляется значение
        }
        variables[m] = sum / matr[m][m];
    }

    return variables;
}



int main ()
{
    int size = 3; // матрица 3х3
    std::vector<std::vector<double>> matr;
    matr = {
            {5, -1, 1},
            {-1, 3, 1},
            {2, 1, 4}
        };
    std::vector<double> b = {-3, -1, 1};

    refill_matrix(matr, b, size);

    totriangle(matr, b);
    std::cout << std::endl << "Ответы: ";
    for (auto a : getanswers(matr, b))
        std::cout << a << "  ";
    std::cout << std::endl;

    return 0;
}
