#include <iostream>

bool isPerfectSquare(int num) 
{

	// Runtime: 1988 ms
	// Memory Usage : 5.7 MB
	
	/*if (num == 1)
	{
		return true;
	}

	if (num % 10 == 2 || num % 10 == 3 || num % 10 == 7 || num % 10 == 8)
	{
		return false;
	}

	for (int i = 2; i <= num / 2; ++i)
	{
		if (num / i == i && num % i == 0)
		{
			return true;
		}
	}
	return false;*/

	// Binary search
	// Runtime: 0 ms
	// Memory Usage : 5.9 MB

	if (num == 1)
	{
		return true;
	}

	int left = 1;
	int right = num;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (mid == num / mid && num % mid == 0)
		{
			return true;
		}
		else if (mid > num / mid)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return false;
}

int main()
{
	isPerfectSquare(12);

	return 0;
}