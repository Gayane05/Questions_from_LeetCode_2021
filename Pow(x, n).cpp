#include <iostream>

double myPow(double x, int n) 
{
	// 304 / 304 test cases passed.
	// Runtime : 0 ms
	// Memory Usage : 6 MB

	if (abs(x) == 0)
	{
		return (n == 0 ? 1 : 0);
	}

	if (abs(x) == 1)
	{
		if (x < 0)
		{
			return (abs(n) % 2 ? -1 : 1);
		}
		return 1;
	}

	if (x == 1)
	{
		return 1;
	}

	if (n == -2147483648)
	{
		if (abs(x) > 1)
		{
			return 0;
		}
	}

	if (n == 2147483647)
	{
		if (abs(x) < 1)
		{
			return 0;
		}
	}

	double number = 1;

	if (n >= 0)
	{
		for (int i = 0; i < abs(n); ++i)
		{
			number *= x;
		}
		return number;
	}

	for (int i = 0; i < abs(n); i++)
	{
		number /= x;
	}
	return number;
}

int main()
{
	myPow(2.00000, -2);

	return 0;
}