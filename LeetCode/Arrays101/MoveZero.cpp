#include "../stdafx.h"


/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/
class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		int writePointer = 0;

		for (int readPointer = 0; readPointer < nums.size(); readPointer++)
		{
			if (nums[readPointer] != 0)
			{
				nums[writePointer] = nums[readPointer];
				writePointer++;
			}
		}
		while (writePointer < nums.size())
			nums[writePointer++] = 0;
	}
};