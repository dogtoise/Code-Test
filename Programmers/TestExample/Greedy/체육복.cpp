#include "../../stdafx.h"
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> reserves;
	for (int i = 0; i < n; i++)
	{
		reserves.push_back(1);
	}


	for (int i = 0; i < reserve.size(); i++)
	{
		reserves[reserve[i] - 1]++;
	}
	for (int i = 0; i < lost.size(); i++)
	{
		reserves[lost[i] - 1]--;
	}

	for (int i = 0; i < reserves.size(); i++)
	{
		if (reserves[i] == 0)
		{
			if (i - 1 >= 0 && reserves[i - 1] == 2)
			{
				reserves[i]++;
				reserves[i - 1]--;
			}
			else if (i + 1 < reserves.size() && reserves[i + 1] == 2)
			{
				reserves[i]++;
				reserves[i + 1] --;
			}
		}
	}
	for (int i = 0; i < reserves.size(); i++)
	{
		if (reserves[i] > 0)
			answer++;
	}

	return answer;
}