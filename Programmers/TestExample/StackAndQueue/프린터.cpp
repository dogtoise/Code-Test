#include "../../stdafx.h"

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// 1. ������� ����
// 2. ���� �߿䵵�� ������ �ִٸ� ���� �ڷ� ����

int solution(vector<int> priorities, int location) {
	int answer = 0;

	// index, priority
	queue<pair<int, int>> workQueue;
	vector<int> workList;

	// queue�� �켱 ������� �����Ѵ�.
	for (int i = 0; i < priorities.size(); i++)
	{
		workQueue.push(make_pair(i, priorities[i]));
		// �۾� ��Ȳ �����
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