#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

void printTable(const vector<vector<double>>& table, const vector<int>& basis, const vector<string>& var_names) {
    int m = table.size();
    int n = table[0].size();
    
    // Вывод заголовков столбцов
    cout << setw(10) << "Базис" << " |";
    for (int j = 0; j < n-1; ++j) {
        cout << setw(8) << var_names[j] << " ";
    }
    cout << setw(8) << "Св.чл." << endl;
    
    // Вывод строк таблицы
    for (int i = 0; i < m; ++i) {
        if (i < basis.size()) {
            cout << setw(10) << var_names[basis[i]] << " |";
        } else {
            cout << setw(10) << "Цель" << " |";
        }
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << fixed << setprecision(2) << table[i][j] << " ";
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

        // 1. Поиск ведущего столбца
        cout << "1. Поиск ведущего столбца (минимальный отрицательный в целевой строке):" << endl;
        int pivot_col = -1;
        for (int j = 0; j < n - 1; ++j) {
            if (table[m - 1][j] < 0 && (pivot_col == -1 || table[m - 1][j] < table[m - 1][pivot_col])) {
                pivot_col = j;
            }
            cout << "  " << var_names[j] << ": " << table[m-1][j];
            if (j == pivot_col) cout << " ← минимальный";
            cout << endl;
        }
        
        if (pivot_col == -1) {
            cout << "Нет отрицательных коэффициентов в целевой строке - оптимум достигнут" << endl;
            break;
        }
        cout << "  Выбран ведущий столбец: " << var_names[pivot_col] << endl << endl;

        // 2. Поиск ведущей строки
        cout << "2. Поиск ведущей строки (минимальное положительное отношение):" << endl;
        int pivot_row = -1;
        double min_ratio = numeric_limits<double>::max();
        for (int i = 0; i < m - 1; ++i) {
            if (table[i][pivot_col] > 0) {
                double ratio = table[i][n - 1] / table[i][pivot_col];
                cout << "  " << var_names[basis[i]] << ": " << table[i][n-1] << " / " << table[i][pivot_col] 
                     << " = " << ratio;
                if (ratio < min_ratio) {
                    min_ratio = ratio;
                    pivot_row = i;
                    cout << " ← новое минимальное";
                }
                cout << endl;
            } else {
                cout << "  " << var_names[basis[i]] << ": коэффициент " << table[i][pivot_col] 
                     << " не положительный - пропускаем" << endl;
            }
        }
        
        if (pivot_row == -1) {
            cout << "Нет положительных коэффициентов в столбце - задача неограничена" << endl;
            return;
        }
        cout << "  Выбрана ведущая строка: " << var_names[basis[pivot_row]] << endl << endl;

        // 3. Обновление базиса
        cout << "3. Обновление базиса:" << endl;
        cout << "  " << var_names[basis[pivot_row]] << " заменяется на " << var_names[pivot_col] << endl;
        basis[pivot_row] = pivot_col;

        // 4. Нормализация ведущей строки
        cout << "4. Нормализация ведущей строки (деление на " << table[pivot_row][pivot_col] << "):" << endl;
        double pivot_val = table[pivot_row][pivot_col];
        for (int j = 0; j < n; ++j) {
            table[pivot_row][j] /= pivot_val;
        }


        // 5. Исключение переменной из других строк
        cout << "5. Исключение переменной из других строк:" << endl;
        for (int i = 0; i < m; ++i) {
            if (i != pivot_row && table[i][pivot_col] != 0) {
                double factor = table[i][pivot_col];
                cout << "  Строка " << var_names[basis[i]] << ": вычитаем " << factor 
                     << " × ведущую строку" << endl;
                for (int j = 0; j < n; ++j) {
                    table[i][j] -= factor * table[pivot_row][j];
                }
            }
        }
        cout << endl;
    }
}

void checkSolution(const vector<double>& solution, const vector<string>& var_names) {
    cout << "\n══════════════════════════════════════════════════════════════" << endl;
    cout << "Проверка решения:\n";
    
    // Проверка ограничений
    cout << "1. x1 + x2 + x3 <= 500: " << solution[0] << " + " << solution[1] 
         << " + " << solution[2] << " = " << (solution[0]+solution[1]+solution[2])
         << ((solution[0]+solution[1]+solution[2] <= 500) ? " <= 500 ✔️" : " > 500 ✘") << endl;
    
    cout << "2. 2x1 + x2 >= 3K: 2*" << solution[0] << " + " << solution[1] << " = " 
         << (2*solution[0]+solution[1]) << " >= 3*" << solution[3] << " = " << (3*solution[3])
         << ((2*solution[0]+solution[1] >= 3*solution[3]) ? " ✔️" : " ✘") << endl;
    
    cout << "3. 2x2 + 3x3 >= 2K: 2*" << solution[1] << " + 3*" << solution[2] << " = " 
         << (2*solution[1]+3*solution[2]) << " >= 2*" << solution[3] << " = " << (2*solution[3])
         << ((2*solution[1]+3*solution[2] >= 2*solution[3]) ? " ✔️" : " ✘") << endl;
    
    // Проверка остатков
    cout << "\nОстатки ресурсов:" << endl;
    cout << "s1 (неисп. прутки): " << solution[4] << (solution[4] == 0 ? " (ресурс использован полностью)" : "") << endl;
    cout << "s2 (резерв огр.2): " << solution[5] << (solution[5] == 0 ? " (ограничение активно)" : "") << endl;
    cout << "s3 (резерв огр.3): " << solution[6] << (solution[6] == 0 ? " (ограничение активно)" : "") << endl;
    
    cout << "Целевая функция K = " << solution[3] << " (максимизируется)" << endl;
}

int main() {
    vector<string> var_names = {"x1", "x2", "x3", "K", "s1", "s2", "s3", "Св.чл."};
    
    vector<vector<double>> table = {
        {  1,   1,   1,   0,   1,  0,  0,  500 },  // s1
        { -2,  -1,   0,   3,   0,  1,  0,    0 },  // s2
        {  0,  -2,  -3,   2,   0,  0,  1,    0 },  // s3
        {  0,   0,   0,  -1,   0,  0,  0,    0 }   // Целевая
    };

    vector<int> basis = {4, 5, 6}; // Начальный базис: s1, s2, s3

    cout << "══════════════════════════════════════════════════════════════" << endl;
    cout << "НАЧАЛЬНАЯ ТАБЛИЦА:" << endl;
    printTable(table, basis, var_names);

    simplexMethod(table, basis, var_names);

    vector<double> solution(7, 0);
    for (int i = 0; i < basis.size(); ++i) {
        if (basis[i] < 7) {
            solution[basis[i]] = table[i][7];
        }
    }

    cout << "══════════════════════════════════════════════════════════════" << endl;
    cout << "ОПТИМАЛЬНОЕ РЕШЕНИЕ:" << endl;
    cout << "x1 = " << solution[0] << " (прутков по варианту 1)" << endl;
    cout << "x2 = " << solution[1] << " (прутков по варианту 2)" << endl;
    cout << "x3 = " << solution[2] << " (прутков по варианту 3)" << endl;
    cout << "K = " << solution[3] << " (комплектов)" << endl;

    checkSolution(solution, var_names);

    return 0;
}

