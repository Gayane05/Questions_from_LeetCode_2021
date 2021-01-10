#include <iostream>
#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target)
{
	// 88 / 88 test cases passed.
	// Runtime : 16 ms
	// Memory Usage : 14.1 MB

	int left = 0;
	int right = nums.size() - 1;
	std::vector<int> range(2, 0);

	if (nums.size() == 1 && nums[0] == target)
	{
		return range;
	}

	if (nums.size() == 2 && nums[0] == target && nums[1] == target)
	{
		range[1] = 1;
		return range;
	}
	
	int count = 0;
	while (left <= right && count <=1)
	{
		int mid = left + (right - left) / 2;

		// For not having infinite loops in situations when target is less than array's first element.
		if (mid == left)
		{
			++count;
		}

		// If target is found.
		if (nums[mid] == target)
		{
			int first_index = mid;
			int second_index = 0;
			int index = -1;

			// Check if elements are after the found one.
			if (mid + 1 < nums.size() && nums[mid + 1] == target)
			{
				int k = mid;
				// For examples like 3,3,3
				while (k + 1 < nums.size() && nums[k + 1] == target)
				{
					second_index = k + 1;
					k += 1;
				}
			}

			// Check if elements are before the found one.
			if (mid - 1 >= 0 && nums[mid - 1] == target)
			{
				int k = mid;
			
				while (k - 1 >= 0 && nums[k - 1] == target)
				{
					index = k - 1;
					k -= 1;
				}
			}
			else
			{
				// If there is only one element that is equal to target.
				// Ex. 1,4
				index = first_index;
			}

			if (second_index > first_index)
			{
				if (first_index < index)
				{
					range[0] = first_index;
				}
				else
				{
					range[0] = index;
				}
				range[1] = second_index;
			}
			else
			{
				range[0] = index;
				range[1] = first_index;
			}
			return range;
		}
		else if (nums[mid] > target)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	range[0] = -1;
	range[1] = -1;

	return range;
}

int main()
{

	std::vector<int> v{ 1, 2, 2};
	searchRange(v, 2);
	return 0;
}
