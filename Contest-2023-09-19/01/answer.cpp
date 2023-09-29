bool is_prime(int num)
{
	if (num % 2 == 0) return false;
	if (num % 3 == 0) return false;
	if (num % 5 == 0) return false;
	
	for (int i = 7; i < num / i+1; i+=2)
	{
		if (num % i == 0) return false;
	}

	return true;
}
