#include <iostream>
#include <tuple>

std::tuple<int, int> reduce(int m, int n)
{
	for (int i = 2; i <= std::min(std::abs(m), n); i++) {
		if (!((m % i) || (n % i)))
		{
			m /= i;
			n /= i;
			i = 1;
		}
	}
	return std::tuple<int, int>(m, n);
}

std::tuple<int, int, int> find_lcm(int n1, int n2)
{
	int i = 1;
	int min = std::min(n1, n2);
	int max = std::max(n1, n2);
	int mul = 0;
	while (true)
	{
		mul = min * i;
		if (!(mul % max))
			return std::tuple<int, int, int>(mul, mul / n1, mul / n2);
		i++;
	}
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
