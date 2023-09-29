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
