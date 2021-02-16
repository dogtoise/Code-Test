#include "../stdafx.h"


/*
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
More formally check if there exists two indices i and j such that :
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
*/

class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		if (arr.size() == 0) return false;


		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = i; j < arr.size(); j++)
			{
				if (i == j) continue;
				if (arr[i] == arr[j] * 2)
					return true;
				if (arr[i] == arr[j] * 0.5f)
					return true;
			}
		}
		return false;
	}
};