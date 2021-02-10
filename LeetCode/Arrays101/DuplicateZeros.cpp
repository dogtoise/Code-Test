#include "../stdafx.h"

/*
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.
Note that elements beyond the length of the original array are not written.
Do the above modifications to the input array in place, do not return anything from your function.
*/

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == 0)
			{
				for (int j = arr.size() - 1; j > i; j--)
				{
					arr[j] = arr[j - 1];
				}
				i++;
			}
		}
	}
};