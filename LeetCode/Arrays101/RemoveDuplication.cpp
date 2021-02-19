/*
iven a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/

#include "../stdafx.h"
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int resultIndex = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[resultIndex] != nums[i])
			{
				resultIndex++;
				nums[resultIndex] = nums[i];
			}
		}

		return resultIndex + 1;
	}
};