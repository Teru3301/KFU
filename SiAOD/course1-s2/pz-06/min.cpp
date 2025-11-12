#include <iostream>
#include <cmath>
#include <array>
#include <stdexcept>

using namespace std;

using Vec2 = array<double,2>;
using Mat2 = array<array<double,2>,2>;

// Функция Розенброка: f(x,y) = (1 - x)^2 + 100*(y - x^2)^2
double f(const Vec2& x) {
    double t1 = 1.0 - x[0];
    double t2 = x[1] - x[0]*x[0];
    return t1*t1 + 100.0*t2*t2;
}

// Градиент Розенброка:
// df/dx = -2*(1 - x) - 400*x*(y - x^2)
// df/dy =  200*(y - x^2)
Vec2 gradient(const Vec2& x) {
    double dx = -2.0*(1.0 - x[0]) - 400.0*x[0]*(x[1] - x[0]*x[0]);
    double dy =  200.0*(x[1] - x[0]*x[0]);
    return {dx, dy};
}

// Гессиан Розенброка:
// d2f/dx2 = 2 - 400*(y - x^2) + 800*x^2
// d2f/dxdy = d2f/dydx = -400*x
// d2f/dy2 = 200
Mat2 hessian(const Vec2& x) {
    double d2xx = 2.0 - 400.0*(x[1] - x[0]*x[0]) + 800.0*x[0]*x[0];
    double d2xy = -400.0*x[0];
    double d2yy = 200.0;
    return {{{d2xx, d2xy}, {d2xy, d2yy}}};
}

// Умножение 2x2 на 2x1
Vec2 matvec(const Mat2& A, const Vec2& v) {
    return {
        A[0][0]*v[0] + A[0][1]*v[1],
        A[1][0]*v[0] + A[1][1]*v[1]
    };
}

// Обратная матрица 2x2
Mat2 inverse(const Mat2& A) {
    double det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    if (fabs(det) < 1e-14) throw runtime_error("Гессиан вырожден");
    double inv = 1.0/det;
    return {{{ A[1][1]*inv, -A[0][1]*inv },
             { -A[1][0]*inv,  A[0][0]*inv }}};
}

// Скалярное произведение
double dot(const Vec2& a, const Vec2& b) {
    return a[0]*b[0] + a[1]*b[1];
}

// Метод Ньютона с бэктрекинг‑поиском (Armijo)
Vec2 newton_rosenbrock(Vec2 x0, double tol=1e-2, int max_iter=100) {
    const double alpha0 = 1.0;   // начальный шаг
    const double rho    = 0.5;   // умножать шаг на rho
    const double c      = 1e-4;  // Armijo‑коэффициент

    Vec2 x = x0;
    for(int k=0; k<max_iter; ++k) {
        Vec2 g = gradient(x);
        double gnorm = sqrt(dot(g,g));
        if (gnorm < tol) {
            cout << "Сошлось за " << k << " итераций, ||grad||=" << std::fixed << gnorm << "\n";
            return x;
        }
        Mat2 H = hessian(x);
        Mat2 Hinv = inverse(H);

        // направление поиска p = -H^{-1} * g
        Vec2 p = matvec(Hinv, g);
        p[0] = -p[0];  p[1] = -p[1];

        // бэктрекинг‑линия поиска
        double alpha = alpha0;
        double fx = f(x);
        while (true) {
            Vec2 x_new = { x[0] + alpha*p[0], x[1] + alpha*p[1] };
            if (f(x_new) <= fx + c*alpha*dot(g,p)) {
                x = x_new;
                break;
            }
            alpha *= rho;
            if (alpha < 1e-5) {
                throw runtime_error("Шаг стал слишком мал");
            }
        }
    }
    cout << "Достигнут максимум итераций, ||grad||=" << fixed << sqrt(dot(gradient(x),gradient(x))) << "\n";
    return x;
}

int main() {
    Vec2 start = { -1.2, 1.0 };  // часто берут эту точку для Розенброка
    try {
        Vec2 xmin = newton_rosenbrock(start);
        cout << "Минимум найден: (" << std::fixed
             << xmin[0] << ", " << xmin[1] << ")\n"
             << "f = " << f(xmin) << "\n";
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << "\n";
    }
    return 0;
}

