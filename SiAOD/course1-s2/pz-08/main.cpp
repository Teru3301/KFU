#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    // Параметры сетки
    const int Nx = 50;       // Узлов по x
    const int Ny = 50;       // Узлов по y
    const double Lx = 1.0;   // Длина по x
    const double Ly = 1.0;   // Длина по y
    const double hx = Lx / (Nx - 1);
    const double hy = Ly / (Ny - 1);
    
    // Параметры решения
    const int max_iter = 10000;
    const double epsilon = 1e-6;
    
    // Инициализация сеток
    vector<vector<double>> phi(Nx, vector<double>(Ny, 0.0));
    vector<vector<double>> phi_new(Nx, vector<double>(Ny, 0.0));
    
    // Граничные условия
    // Левая граница (x=0): 0, правая (x=Lx): 100
    for (int j = 0; j < Ny; j++) {
        phi[0][j] = 0.0;
        phi[Nx-1][j] = 100.0;
    }
    // Верхняя и нижняя границы (y=0, y=Ly): 0
    for (int i = 0; i < Nx; i++) {
        phi[i][0] = 0.0;
        phi[i][Ny-1] = 0.0;
    }
    phi_new = phi; // Копируем граничные условия
    
    // Итерационный процесс (Якоби)
    int iter;
    double max_diff;
    for (iter = 0; iter < max_iter; iter++) {
        max_diff = 0.0;
        
        // Обновление внутренних узлов
        for (int i = 1; i < Nx-1; i++) {
            for (int j = 1; j < Ny-1; j++) {
                // Дискретизация уравнения Лапласа
                phi_new[i][j] = ((phi[i+1][j] + phi[i-1][j])/(hx*hx) + 
                                (phi[i][j+1] + phi[i][j-1])/(hy*hy)) / 
                                (2.0/(hx*hx) + 2.0/(hy*hy));
                
                // Обновление максимального изменения
                max_diff = max(max_diff, abs(phi_new[i][j] - phi[i][j]));
            }
        }
        
        // Проверка сходимости
        if (max_diff < epsilon) break;
        
        // Обновление сетки
        for (int i = 1; i < Nx-1; i++) {
            for (int j = 1; j < Ny-1; j++) {
                phi[i][j] = phi_new[i][j];
            }
        }
    }
    
    // Вывод результатов
    cout << "Итераций: " << iter << endl;
    cout << "Максимальное изменение: " << fixed << max_diff << endl;
    
    // Сохранение в файл
    ofstream out("laplace.txt");
    for (int i = 0; i < Nx; i++) {
        for (int j = 0; j < Ny; j++) {
            out << phi[i][j] << " ";
        }
        out << endl;
    }
    out.close();
    
    return 0;
}
