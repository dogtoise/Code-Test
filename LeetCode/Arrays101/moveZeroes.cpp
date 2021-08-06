#include "../stdafx.h"

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int readPointer = 0;
		int writePointer = 0;

		for (readPointer = 0; readPointer < nums.size(); readPointer++)
		{
			if (nums[readPointer] != 0)
			{
				nums[writePointer++] = nums[readPointer];
			}
		}
		for (; writePointer < nums.size(); writePointer++)
		{
			nums[writePointer] = 0;
		}
	}
};