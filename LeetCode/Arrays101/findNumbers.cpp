#include "../stdafx.h"

/*
Given an array nums of integers, return how many of them contain an even number of digits.
*/

class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int cnt = 0;
		for (int i = 0; i < nums.size(); i++)
		{

			int temp = 1;

			for (int j = 1; j < 7; j++)
			{
				if ((nums[i] / pow(10, j)) < 1)
				{
					temp = j;
					break;
				}
			}
			if (temp % 2 == 0)
			{
				cnt++;
			}
		}
		return cnt;
	}
};