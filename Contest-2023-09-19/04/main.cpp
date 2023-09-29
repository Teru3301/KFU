// для того что бы код работал нужен с++17
#include <iostream>
#include <tuple>

// Ваш код будет вставлен сюда
std::tuple <int, int> reduce(int m, int n)
{
    if (m == n) return std::tuple<int, int>(1, 1);

    int tmp = std::min(abs(m), abs(n));
    while (tmp > 0)
    {
        if (m % 2 == 0 && n % 2 == 0)
        {
            m /= 2;
            n /= 2;
            continue;
        }
        if (m % tmp == 0 && n % tmp == 0)
        {
            m /= tmp;
            n /= tmp;
        }
        tmp--;
    }
    return std::tuple<int, int>(m, n);
}

std::tuple <int, int, int> find_lcm(int n1, int n2)
{
    int lcm = std::min(n1, n2);

    if (n1 == n2) return std::tuple<int, int, int>(n1, lcm / n1, lcm / n2);

    while (lcm % std::max(n1, n2) != 0)
    {
        lcm += std::min(n1, n2);
    }

    int c1 = lcm / n1;
    int c2 = lcm / n2;

    return std::tuple<int, int, int>(lcm, c1, c2);
}


int main() {
    int m1, n1, m2, n2;
    char _;
    std::cin >> m1 >> _ >> n1
             >> m2 >> _ >> n2;
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    auto[lcm, c1, c2] = find_lcm(n1, n2);
    auto[m, n] = reduce(m1 * c1 + m2 * c2, lcm);

    std::cout << m << '/' << n << std::endl;
}
