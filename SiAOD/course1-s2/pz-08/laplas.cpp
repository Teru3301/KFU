
#include <iostream>
#include <vector>
#include <iomanip>

int main ()
{
    double x = 0;
    double y = 0;

    int N = 10;
    int M = 10;

    double u_x0 = 1;
    double u_xb = 1;
    double u_0y = 1;
    double u_ay = 0;

    double tol = 0.0001;


//  создание пустой сетки
    std::vector<std::vector<double>> u;
    for (int n = 0; n < N; n++)
    {
        std::vector<double> tmp;
        for (int m = 0; m < M; m++)
            tmp.push_back(0);
        u.push_back(tmp);
    }
//  добавление значений на границах
    for (int n = 0; n < N; n++)
    {
        u[n][0]   = u_x0;
        u[n][M-1] = u_xb;
    }
    for (int m = 0; m < M; m++)
    {
        u[0][m]   = u_0y;
        u[N-1][m] = u_ay;
    }


    std::cout << "Начальные значения:" << std::endl;
    std::cout << "\tx = " << x << std::endl;
    std::cout << "\ty = " << y << std::endl;
    std::cout << "\t---------" << std::endl;
    std::cout << "\tu(x, 0) = " << u_x0 << std::endl;
    std::cout << "\tu(x, b) = " << u_xb << std::endl;
    std::cout << "\tu(0, y) = " << u_0y << std::endl;
    std::cout << "\tu(a, y) = " << u_ay << std::endl;
    std::cout << "\t---------" << std::endl;
    std::cout << "\tNxM = " << N << 'x' << M << std::endl;
    std::cout << std::endl;




    std::vector<std::vector<double>> u_new = u;
    int max_iter = 1000;

    for (int it = 0; it < max_iter; ++it)
    {
        double max_diff = 0.0;

        for (int i = 1; i < N - 1; ++i)
        {
            for (int j = 1; j < M - 1; ++j)
            {
                u_new[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]);
                double diff = std::abs(u_new[i][j] - u[i][j]);
                if (diff > max_diff) max_diff = diff;
            }
        }

        u = u_new;

        if (max_diff < tol) {
            std::cout << "Сошлось за " << it << " итераций." << std::endl;
            break;
        }
    }

    std::cout << std::endl;

    for (auto i : u)
    {
        for (auto j : i)
        {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}



