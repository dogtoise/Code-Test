#include "../stdafx.h"

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		if (nums.size() == 0)
			return nums;

		vector<int> oddNums;

		int writePointer = 0;
		int readPointer = 0;
		for (; readPointer < nums.size(); readPointer++)
		{
			if (nums[readPointer] % 2 == 0)
			{

				nums[writePointer++] = nums[readPointer];
			}
			else
			{
				oddNums.push_back(nums[readPointer]);
			}
		}

		for (int i = 0; i < oddNums.size(); i++)
		{
			nums[writePointer++] = oddNums[i];
		}
		return nums;
	}
};