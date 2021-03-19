#include "../stdafx.h"

/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.
*/

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {

		int oddIndex = A.size() - 1;
		int temp;
		for (int i = 0; i <= oddIndex; i++)
		{
			if (A[i] % 2 == 1)
			{
				temp = A[oddIndex];
				A[oddIndex] = A[i];
				A[i] = temp;
				i--;
				oddIndex--;
			}
		}
		return A;
	}
};