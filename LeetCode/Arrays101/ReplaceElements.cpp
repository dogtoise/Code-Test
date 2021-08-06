/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
After doing so, return the array.
*/


// Your runtime beats 94.32 % of cpp submissions.

#include "../stdafx.h"
class Solution {
public:

	vector<int> replaceElements(vector<int>& arr) {
		if (arr.size() == 1)
		{
			arr[0] = -1;
			return arr;
		}

		int max = arr[arr.size() - 1];

		for (int i = arr.size() - 1; i >= 0; i--)
		{
			int temp = max;
			if (max <= arr[i])
			{
				max = arr[i];
			}
			arr[i] = temp;
		}
		arr[arr.size() - 1] = -1;

		return arr;
	}
};