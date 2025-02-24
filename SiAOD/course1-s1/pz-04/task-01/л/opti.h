

double opti (double x, double e)
{
	double answer = 0.0;
	double x_squared = x * x;
	double member = 1.0;

	double numerator = 1;
	double k_factorial = 1;

	int k = 1;

	for (; std::fabs(member) >= e; k++)
	{
		answer += member;

		numerator = numerator * x_squared;
		k_factorial = k_factorial * k;
		
		member = numerator / (2 * k_factorial);
	}

	std::cout << "\n k - " << k << '\n';

	return answer;
}
