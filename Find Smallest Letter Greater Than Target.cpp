#include <iostream>
#include <vector>

char nextGreatestLetter(std::vector<char>& letters, char target) 
{
	// 165 / 165 test cases passed.
	// Runtime: 12 ms // 99.92%
	// Memory Usage: 15.7 MB 

	int l = 0;
	int r = letters.size();
	int last_big_el = 0;

	int mid = l + (r - l) / 2;

	while (l < r)
	{
		mid = l + (r - l) / 2;

		if (letters[mid] == target)
		{
			last_big_el = ++mid;
			break;
		}
		else if(letters[mid] > target)
		{
			r = mid;
			last_big_el = mid;
		}
		else if (letters[mid] < target)
		{
			l = mid + 1;
			last_big_el = mid + 1;
		}
	}
	if (last_big_el >= letters.size())
	{
		return letters[0];
	}
	return letters[last_big_el];
}

int main()
{
	std::vector<char> let {'c', 'f', 'j'};

	nextGreatestLetter(let, 'd');

	return 0;
}
