#include "../../stdafx.h"

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	// weight
	queue<int> truckQueue;
	// ���൵, weight
	vector<pair<int, int>> progress;

	for (int i = 0; i < truck_weights.size(); i++)
	{
		truckQueue.push(truck_weights[i]);
	}

	int step = 0;
	while (!truckQueue.empty() || !progress.empty())
	{
		step++;
		// ���൵�� �����Ѵ�.
		for (int i = 0; i < progress.size(); i++)
		{
			// �Ѿ�µ� �������� ���
			// �������ش�.
			progress[i].first++;
			if (progress[i].first > bridge_length)
			{
				progress.erase(progress.begin() + i);
				i--;
			}
		}
		if (!truckQueue.empty())
		{

			int curWeight = 0;
			// ���� �������� ���Ը� ���Ѵ�.
			for (int i = 0; i < progress.size(); i++)
			{
				curWeight += progress[i].second;
			}

			// ���ο� Ʈ���� ���Ը� ���Ѵ�.
			int newWeight = truckQueue.front();

			// ���ο� Ʈ���� �ö� �� �ִٸ� �߰��Ѵ�.
			if (curWeight + newWeight <= weight)
			{
				truckQueue.pop();
				progress.push_back(make_pair(1, newWeight));
			}
		}

	}
	answer = step;
	return answer;
}