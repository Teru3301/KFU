//  Дискретное преобразование фурье
//  
//  


#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "furie.hpp"


double f(double x)
{
    return std::sin(x);
}


int main()
{
    std::vector<Point> point;    //  точки
    double step = 0.1;          //  шаг между точками
    double T    = 2 * PI;        //  интервал


    //  создание точек
    for (int i = 0; i*step <= T; i++)
    {
        Point p;
        p.x = i * step;
        p.y = f(p.x);
        point.push_back(p);
    } 


    std::vector<Harmonic> harmonic = DTF(point);


    std::cout << std::fixed << std::setprecision(6);
    for (int i = 0; i < harmonic.size(); i++)
    {
        double h_sin = harmonic[i].sin;
        double h_cos = harmonic[i].cos;
        std::cout << "Гармоника-" << i << ":\t[" << h_cos << ", " << h_sin << "]" << std::endl;
    }


    std::cout << point.size() << " <<<<<<<<<<<<<<";

    while (true)
    {
        double x;
        std::cout << "x    = ";
        std::cin >> x;
        std::cout << "y    = " << restored(harmonic, x, T) << std::endl;
        std::cout << "f(x) = " << f(x) << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }



    return 0;
}




