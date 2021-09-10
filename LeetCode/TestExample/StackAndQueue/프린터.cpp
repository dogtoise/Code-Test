#include "../../stdafx.h"

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// 1. 순서대로 진행
// 2. 만약 중요도가 높은게 있다면 제일 뒤로 보냄

int solution(vector<int> priorities, int location) {
	int answer = 0;

	// index, priority
	queue<pair<int, int>> workQueue;
	vector<int> workList;

	// queue에 우선 순서대로 저장한다.
	for (int i = 0; i < priorities.size(); i++)
	{
		workQueue.push(make_pair(i, priorities[i]));
		// 작업 현황 저장용
		workList.push_back(priorities[i]);
	}

	int step = 0;
	while (!workQueue.empty())
	{
		pair<int, int> curWork = workQueue.front();
		workQueue.pop();

		bool bPrint = true;
		for (int i = 0; i < workList.size(); i++)
		{
			if (workList[i] > curWork.second)
			{
				bPrint = false;
				workQueue.push(curWork);
				break;
			}
		}
		if (bPrint)
		{
			step++;
			workList[curWork.first] = -1;

			if (curWork.first == location)
			{
				answer = step;
				return answer;
			}

		}
	}

	return answer;
}