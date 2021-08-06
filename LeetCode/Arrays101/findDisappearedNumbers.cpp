#include "../stdafx.h"

/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
*/

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {

		vector<int> temp(nums.size() + 1, 0);
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			temp[nums[i]]++;
		}

		for (int i = 1; i < temp.size(); i++)
		{
			if (temp[i] == 0)
				result.push_back(i);
		}
		return result;

	}
};