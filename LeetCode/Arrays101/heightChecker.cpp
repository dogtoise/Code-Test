#include "../stdafx.h"

class Solution {
public:
	int heightChecker(vector<int>& heights) {

		vector<int> temp = heights;

		sort(heights.begin(), heights.end());

		int res = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			if (temp[i] != heights[i])
				res++;
		}

		return res;
	}
};