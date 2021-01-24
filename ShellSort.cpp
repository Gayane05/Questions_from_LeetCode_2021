#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void ShellSort(std::vector<T> arr)
{
	int size = arr.size();
	int h = 1;
	while (h < size / 3)
	{
		h = 3 * h + 1;
	}

	while (h >= 1)
	{
		for (int i = h; i < size; ++i)
		{
			for (int j = i; j >= h && (arr[j] < arr[j - h]); j -= h)
			{
				std::swap(arr[j], arr[j - h]);
			}
		}
		h = h / 3;
	}
}


int main()
{
	std::vector<char> example{ 'S','O','R','T','E','X','A','M','P','L','E' };
	ShellSort(example);


	return 0;
}
