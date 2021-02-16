#include "../stdafx.h"

/*
Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
*/

class Solution {
public:
	bool validMountainArray(vector<int>& arr) {
		if (arr.size() < 3) return false;

		bool isIncrease = true;
		int prevNumber = arr[0];
		for (int i = 1; i < arr.size(); i++)
		{
			if (prevNumber < arr[i])
			{
				if (isIncrease == false)
					return false;
			}
			else if (prevNumber > arr[i])
			{
				if (isIncrease && i == 1)
					return false;
				if (isIncrease)
					isIncrease = false;
			}
			else
				return false;
			prevNumber = arr[i];
		}
		if (isIncrease == true) return false;
		return true;
	}
};