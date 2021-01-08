#include <iostream>

int kthFactor(int n, int k) 
{
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (n % i == 0) 
		{
			++count;
			// If the number is kth that we want, then return it, otherwise check next numbers.
			if (count == k)
			{
				return i;
			}
		}
	}
	return -1;
}

int main()
{
    
	kthFactor(1000, 3);
	return 0;
}
