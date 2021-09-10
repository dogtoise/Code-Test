#include "../../stdafx.h"

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 1. 작업 현황을 queue에 넣는다. 
// 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	if (progresses.size() > 100)
		return answer;

	// index
	queue<int> workIndeces;
	// progresses, speeds
	vector<pair<int, int>> works;

	for (int i = 0; i < progresses.size(); i++)
	{
		workIndeces.push(i);
		works.push_back(make_pair(progresses[i], speeds[i]));
	}

	while (!workIndeces.empty())
	{
		int curWorkIndex = workIndeces.front();
		int completeCount = 0;
		for (int i = curWorkIndex; i < works.size(); i++)
		{
			if (works[i].first >= 100)
			{
				completeCount++;
				workIndeces.pop();
			}
			else
				break;
		}
		if (completeCount > 0)
			answer.push_back(completeCount);

		for (int i = 0; i < works.size(); i++)
		{
			works[i].first += works[i].second;
		}

	}

	return answer;
}