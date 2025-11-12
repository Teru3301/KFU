#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

void printTable(const vector<vector<double>>& table, const vector<int>& basis, const vector<string>& var_names) {
    int m = table.size();
    int n = table[0].size();

    // Вывод заголовков
    cout << setw(10) << "Базис" << " |";
    for (int j = 0; j < n-1; ++j) {
        cout << setw(10) << var_names[j] << " ";
    }
    cout << setw(10) << "Св.чл." << endl;

    // Вывод строк
    for (int i = 0; i < m; ++i) {
        if (i < basis.size()) {
            cout << setw(5) << var_names[basis[i]] << " |";
        } else {
            cout << setw(9) << "Цель" << " |";
        }
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << fixed << setprecision(2) << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void simplexMethod(vector<vector<double>>& table, vector<int>& basis, const vector<string>& var_names) {
    int m = table.size();
    int n = table[0].size();
    int iteration = 1;

    while (true) {
        cout << "══════════════════════════════════════════════════════════════" << endl;
        cout << "Итерация " << iteration++ << ":" << endl;
        printTable(table, basis, var_names);

        // 1. Поиск ведущего столбца (минимальный отрицательный в целевой строке)
        int pivot_col = -1;
        double min_val = 0;
        for (int j = 0; j < n-1; ++j) {
            if (table.back()[j] < min_val) {
                min_val = table.back()[j];
                pivot_col = j;
            }
        }
        if (pivot_col == -1) {
            cout << "Оптимум достигнут" << endl;
            break;
        }
        cout << "Ведущий столбец: " << var_names[pivot_col] << endl;

        // 2. Поиск ведущей строки (минимальное положительное отношение)
        int pivot_row = -1;
        double min_ratio = numeric_limits<double>::max();
        for (int i = 0; i < m-1; ++i) {
            if (table[i][pivot_col] > 0) {
                double ratio = table[i].back() / table[i][pivot_col];
                if (ratio < min_ratio) {
                    min_ratio = ratio;
                    pivot_row = i;
                }
            }
        }
        if (pivot_row == -1) {
            cout << "Задача неограничена" << endl;
            return;
        }
        cout << "Ведущая строка: " << var_names[basis[pivot_row]] << endl;

        // 3. Обновление базиса
        basis[pivot_row] = pivot_col;

        // 4. Нормализация ведущей строки
        double pivot_val = table[pivot_row][pivot_col];
        for (int j = 0; j < n; ++j) {
            table[pivot_row][j] /= pivot_val;
        }

        // 5. Исключение переменной из других строк
        for (int i = 0; i < m; ++i) {
            if (i != pivot_row) {
                double factor = table[i][pivot_col];
                for (int j = 0; j < n; ++j) {
                    table[i][j] -= factor * table[pivot_row][j];
                }
            }
        }
    }
}

int main() {
    vector<string> var_names = {"s3", "s4", "s1", "s2", "Св.чл."};
    
    // Инициализация симплекс-таблицы (после подстановки x1=4+s3, x2=12+s4)
    vector<vector<double>> table = {
        {2.5, 5, 1, 0, 10},    // s1
        {7.5, 10, 0, 1, 30},   // s2
        {-160, -600, 0, 0, 0}  // Цель
    };
    
    vector<int> basis = {2, 3}; // Начальный базис: s1, s2

    cout << "══════════════════════════════════════════════════════════════" << endl;
    cout << "НАЧАЛЬНАЯ ТАБЛИЦА:" << endl;
    printTable(table, basis, var_names);

    simplexMethod(table, basis, var_names);

    // Извлекаем решение для s3 и s4
    double s3 = 0, s4 = 0;
    for (size_t i = 0; i < basis.size(); ++i) {
        if (basis[i] == 0) s3 = table[i].back();
        if (basis[i] == 1) s4 = table[i].back();
    }

    // Восстанавливаем x1 и x2
    double x1 = 4 + s3;
    double x2 = 12 + s4;
    double Z = 160*x1*2.5 + 600*x2;

    cout << "══════════════════════════════════════════════════════════════" << endl;
    cout << "ОПТИМАЛЬНОЕ РЕШЕНИЕ:" << endl;
    cout << "x1 (комплекты пиломатериалов) = " << x1 << endl;
    cout << "x2 (листы фанеры) = " << x2 << endl;
    cout << "Максимальный доход: " << Z << " руб." << endl;

    // Проверка ограничений
    cout << "\n══════════════════════════════════════════════════════════════" << endl;
    cout << "Проверка ограничений:\n";
    cout << "1. Еловые: 2.5*" << x1 << " + 5*" << x2 << " = " 
         << 2.5*x1 + 5*x2 << " <= 80 → " 
         << ((2.5*x1 + 5*x2 <= 80) ? "✔️" : "✘") << endl;
    
    cout << "2. Пихтовые: 7.5*" << x1 << " + 10*" << x2 << " = " 
         << 7.5*x1 + 10*x2 << " <= 180 → " 
         << ((7.5*x1 + 10*x2 <= 180) ? "✔️" : "✘") << endl;
    
    cout << "3. Минимум пиломатериалов: " << x1 << " >= 4 → " 
         << ((x1 >= 4) ? "✔️" : "✘") << endl;
    
    cout << "4. Минимум фанеры: " << x2 << " >= 12 → " 
         << ((x2 >= 12) ? "✔️" : "✘") << endl;


    return 0;
}
