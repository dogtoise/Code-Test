#include "../stdafx.h"

/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
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