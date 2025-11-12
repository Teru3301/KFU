
#include <iostream>
#include <vector>
#include <climits>


struct Solution {
    int x1, x2, x3;
    int F;
};

int main() {
    int min_F = INT_MAX;
    std::vector<Solution> best_solutions;

    const int max_x1 = 10;
    const int max_x2 = 10;

    for (int x1 = 0; x1 <= max_x1; ++x1) {
        for (int x2 = 0; x2 <= max_x2; ++x2) {
            int x3 = 2 * x1 + x2 - 3;

            // Проверка ограничений
            bool constraint1 = (x3 >= 0);          // x3 >= 0
            bool constraint2 = (2 * x1 - 7 * x2 <= 1);
            bool constraint3 = (2 * x1 + 3 * x2 >= 6);

            if (constraint1 && constraint2 && constraint3) {
                int F = x1 + 2 * x2;

                if (F < min_F) {
                    min_F = F;
                    best_solutions.clear();
                    best_solutions.push_back({x1, x2, x3, F});
                } else if (F == min_F) {
                    best_solutions.push_back({x1, x2, x3, F});
                }
            }
        }
    }

    // Вывод результатов
    std::cout << "Минимальное значение F: " << min_F << std::endl;
    std::cout << "Оптимальные решения:" << std::endl;
    for (const auto& sol : best_solutions) {
        std::cout << "x1 = " << sol.x1 << ", x2 = " << sol.x2 << ", x3 = " << sol.x3 << std::endl;
        std::cout << "Проверка ограничений:" << std::endl;
        std::cout << "2*x1 + x2 - x3 = " << 2*sol.x1 + sol.x2 - sol.x3 << " = 3" << std::endl;
        std::cout << "2*x1 - 7*x2 = " << 2*sol.x1 - 7*sol.x2 << " <= 1" << std::endl;
        std::cout << "2*x1 + 3*x2 = " << 2*sol.x1 + 3*sol.x2 << " >= 6" << std::endl;
    }

    return 0;
}

