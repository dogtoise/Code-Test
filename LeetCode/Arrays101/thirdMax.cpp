#include "../stdafx.h"


class Solution {
public:
	int thirdMax(vector<int>& nums) {
		sort(nums.begin(), nums.end());


		int temp = 0;
		for (int i = nums.size() - 1; i >= 1; i--)
		{
			if (nums[i] != nums[i - 1])
				temp++;

			if (temp == 2)
			{
				return nums[i - 1];
			}
		}

		return nums[nums.size() - 1];

	}
};