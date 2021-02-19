/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
After doing so, return the array.
*/


// Your runtime beats 94.32 % of cpp submissions.

#include "../stdafx.h"
class Solution {
public:

	vector<int> replaceElements(vector<int>& arr) {
		int max;

		max = arr[arr.size() - 1];
		arr[arr.size() - 1] = -1;
		for (int i = arr.size() - 2; i >= 0; i--)
		{
			if (arr[i] > max)
			{
				int temp = arr[i];
				arr[i] = max;
				max = temp;
			}
			else
				arr[i] = max;
		}


		return arr;
	}
};