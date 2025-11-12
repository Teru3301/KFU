
#include <iostream>
#include <vector>
#include <iomanip>


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

void render3DBars(const std::vector<std::vector<double>>& u) {
    // Инициализация GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    // Создание окна
    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Bars Visualization", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    
    // Инициализация GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return;
    }

    // Настройки OpenGL
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 800.0/600.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);

    // Основной цикл рендеринга
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        
        // Установка камеры
        gluLookAt(-20, 10, 10,  // позиция камеры
                 15, 0, 10,      // точка наведения
                 0, 1, 0);      // вектор "вверх"

        // Отрисовка осей
        glBegin(GL_LINES);
        // Ось X (красная)
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(5, 0, 0);
        // Ось Y (зелёная)
        glColor3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 2, 0);
        // Ось Z (синяя)
        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 5);
        glEnd();

        // Отрисовка столбцов
        for (size_t i = 0; i < u.size(); ++i) {
            for (size_t j = 0; j < u[i].size(); ++j) {
                float height = u[i][j];
                float x = i;
                float z = j;
                
                // Установка цвета (от синего к красному в зависимости от высоты)
                glColor3f(height, 0, 1 - height);
                
                // Рисуем столбец как куб
                glBegin(GL_QUADS);
                // Основание
                glVertex3f(x, 0, z);
                glVertex3f(x+0.8f, 0, z);
                glVertex3f(x+0.8f, 0, z+0.8f);
                glVertex3f(x, 0, z+0.8f);
                
                // Боковые грани
                // Передняя
                glVertex3f(x, 0, z);
                glVertex3f(x+0.8f, 0, z);
                glVertex3f(x+0.8f, height, z);
                glVertex3f(x, height, z);
                // Правая
                glVertex3f(x+0.8f, 0, z);
                glVertex3f(x+0.8f, 0, z+0.8f);
                glVertex3f(x+0.8f, height, z+0.8f);
                glVertex3f(x+0.8f, height, z);
                // Задняя
                glVertex3f(x, 0, z+0.8f);
                glVertex3f(x+0.8f, 0, z+0.8f);
                glVertex3f(x+0.8f, height, z+0.8f);
                glVertex3f(x, height, z+0.8f);
                // Левая
                glVertex3f(x, 0, z);
                glVertex3f(x, 0, z+0.8f);
                glVertex3f(x, height, z+0.8f);
                glVertex3f(x, height, z);
                // Верхняя
                glVertex3f(x, height, z);
                glVertex3f(x+0.8f, height, z);
                glVertex3f(x+0.8f, height, z+0.8f);
                glVertex3f(x, height, z+0.8f);
                glEnd();
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

int main ()
{
    double x = 0;
    double y = 0;

    int N = 10;
    int M = 10;

    double u_x0 = 0.5;
    double u_xb = 0.5;
    double u_0y = 0;
    double u_ay = 1;

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

    render3DBars(u);


    return 0;
}



