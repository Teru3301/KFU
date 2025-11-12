import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp
import matplotlib.animation as animation

# ------------------------------
# 1. Параметры задачи
# ------------------------------
L = 1.0        # длина струны
c = 1.0        # скорость волны
n = 5          # число базисных функций = точек коллокации
T = 2.0        # конечное время
num_t = 200    # количество шагов по времени
x_plot = np.linspace(0, L, 300)  # точки для построения графика

# ------------------------------
# 2. Базисные функции и производные
# ------------------------------
def phi(i, x):
    return np.sin((i + 1) * np.pi * x)

def phi_dd(i, x):
    return -((i + 1) * np.pi) ** 2 * np.sin((i + 1) * np.pi * x)

# ------------------------------
# 3. Точки коллокации (не включая граничные)
# ------------------------------
x_colloc = np.linspace(0, L, n + 2)[1:-1]  # исключаем 0 и 1

# ------------------------------
# 4. Сборка матриц M (масса) и K (жесткость)
#    Система: M * a''(t) = c^2 * K * a(t)
# ------------------------------
M = np.zeros((n, n))
K = np.zeros((n, n))

for j in range(n):
    for i in range(n):
        M[j, i] = phi(i, x_colloc[j])     # φ_i(x_j)
        K[j, i] = phi_dd(i, x_colloc[j])  # φ_i''(x_j)

# ------------------------------
# 5. Начальные условия: u(x,0) = sin(pi x), u_t(x,0) = 0
# ------------------------------
def u0(x):
    return np.sin(np.pi * x)

# Вычисляем начальные коэффициенты a(0) через систему M @ a0 = u0(x_colloc)
b = np.array([u0(xj) for xj in x_colloc])
a0 = np.linalg.solve(M, b)
v0 = np.zeros_like(a0)  # начальная скорость = 0

# ------------------------------
# 6. Система ОДУ: y = [a, v], где v = da/dt
# ------------------------------
def ode_system(t, y):
    a = y[:n]
    v = y[n:]
    a_dd = c**2 * np.linalg.solve(M, K @ a)  # из M*a'' = c^2*K*a
    return np.concatenate((v, a_dd))

# ------------------------------
# 7. Численное решение системы ОДУ
# ------------------------------
y0 = np.concatenate((a0, v0))
t_eval = np.linspace(0, T, num_t)
sol = solve_ivp(ode_system, (0, T), y0, t_eval=t_eval)

# ------------------------------
# 8. Восстановим u(x, t) для графика
# ------------------------------
u_xt = []
for k in range(len(t_eval)):
    a_t = sol.y[:n, k]
    u_t = sum(a_t[i] * phi(i, x_plot) for i in range(n))
    u_xt.append(u_t)
u_xt = np.array(u_xt)

# ------------------------------
# 9. Анимация колебания струны
# ------------------------------
fig, ax = plt.subplots()
line, = ax.plot([], [], lw=2)
ax.set_xlim(0, L)
ax.set_ylim(-1.2, 1.2)
ax.set_xlabel('x')
ax.set_ylabel('u(x, t)')
ax.set_title('Колебание струны: метод точечной коллокации')

def init():
    line.set_data([], [])
    return line,

def animate(i):
    line.set_data(x_plot, u_xt[i])
    ax.set_title(f'Колебание струны, t = {t_eval[i]:.2f} c')
    return line,

ani = animation.FuncAnimation(fig, animate, frames=len(t_eval),
                              init_func=init, blit=True, interval=30)

plt.show()

