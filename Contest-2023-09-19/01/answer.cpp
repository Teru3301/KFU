bool is_prime(int num)
{
	if (num % 2 == 0) return false;

	for (int i = 3; i < num / (i-1); i+=2)
	{
		if (num % i == 0) return false;
	}

	return true;
}
