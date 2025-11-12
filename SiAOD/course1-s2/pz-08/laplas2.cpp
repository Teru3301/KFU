#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Решение уравнения Лапласа (ваш исходный код)
std::vector<std::vector<double>> solveLaplaceEquation() {
    int N = 10, M = 10;
    std::vector<std::vector<double>> u(N, std::vector<double>(M, 0));

    // Граничные условия
    for (int n = 0; n < N; n++) {
        u[n][0]   = 1;  // u(x, 0) = 1
        u[n][M-1] = 1;  // u(x, b) = 1
    }
    for (int m = 0; m < M; m++) {
        u[0][m]   = 1;  // u(0, y) = 1
        u[N-1][m] = 0;  // u(a, y) = 0
    }

    // Решение уравнения
    std::vector<std::vector<double>> u_new = u;
    double tol = 0.0001;
    int max_iter = 1000;

    for (int it = 0; it < max_iter; ++it) {
        double max_diff = 0.0;
        for (int i = 1; i < N - 1; ++i) {
            for (int j = 1; j < M - 1; ++j) {
                u_new[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]);
                double diff = std::abs(u_new[i][j] - u[i][j]);
                if (diff > max_diff) max_diff = diff;
            }
        }
        u = u_new;
        if (max_diff < tol) break;
    }

    return u;
}

// Отрисовка 3D-столбцов
void render3DBars(const std::vector<std::vector<double>>& u) {
    if (!glfwInit()) {
        std::cerr << "Ошибка инициализации GLFW!" << std::endl;
        return;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Столбцы решения уравнения Лапласа", NULL, NULL);
    if (!window) {
        std::cerr << "Ошибка создания окна!" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(15, 15, 15, 5, 0, 5, 0, 1, 0);  // Камера смотрит на сетку

        // Отрисовка осей (X, Y, Z)
        glBegin(GL_LINES);
        // Ось X (красная)
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(20, 0, 0);
        // Ось Y (зелёная)
        glColor3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 2, 0);
        // Ось Z (синяя)
        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 20);
        glEnd();

        // Отрисовка столбцов
        for (size_t i = 0; i < u.size(); ++i) {
            for (size_t j = 0; j < u[i].size(); ++j) {
                float height = u[i][j];
                float x = i * 1.0f;
                float z = j * 1.0f;

                // Цвет столбца (зависит от высоты)
                glColor3f(0.2f, 0.5f, height);

                // Основание столбца (квадрат)
                glBegin(GL_QUADS);
                glVertex3f(x, 0, z);
                glVertex3f(x + 0.8f, 0, z);
                glVertex3f(x + 0.8f, 0, z + 0.8f);
                glVertex3f(x, 0, z + 0.8f);
                glEnd();

                // Боковые грани столбца
                glBegin(GL_QUADS);
                // Передняя грань
                glVertex3f(x, 0, z);
                glVertex3f(x + 0.8f, 0, z);
                glVertex3f(x + 0.8f, height, z);
                glVertex3f(x, height, z);
                // Правая грань
                glVertex3f(x + 0.8f, 0, z);
                glVertex3f(x + 0.8f, 0, z + 0.8f);
                glVertex3f(x + 0.8f, height, z + 0.8f);
                glVertex3f(x + 0.8f, height, z);
                // Задняя грань
                glVertex3f(x, 0, z + 0.8f);
                glVertex3f(x + 0.8f, 0, z + 0.8f);
                glVertex3f(x + 0.8f, height, z + 0.8f);
                glVertex3f(x, height, z + 0.8f);
                // Левая грань
                glVertex3f(x, 0, z);
                glVertex3f(x, 0, z + 0.8f);
                glVertex3f(x, height, z + 0.8f);
                glVertex3f(x, height, z);
                // Верхняя грань
                glVertex3f(x, height, z);
                glVertex3f(x + 0.8f, height, z);
                glVertex3f(x + 0.8f, height, z + 0.8f);
                glVertex3f(x, height, z + 0.8f);
                glEnd();
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

int main() {
    auto solution = solveLaplaceEquation();
    render3DBars(solution);
    return 0;
}
