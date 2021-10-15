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
	// 진행도, weight
	vector<pair<int, int>> progress;

	for (int i = 0; i < truck_weights.size(); i++)
	{
		truckQueue.push(truck_weights[i]);
	}

	int step = 0;
	while (!truckQueue.empty() || !progress.empty())
	{
		step++;
		// 진행도를 갱신한다.
		for (int i = 0; i < progress.size(); i++)
		{
			// 넘어가는데 성공했을 경우
			// 제거해준다.
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
			// 현재 진행중인 무게를 구한다.
			for (int i = 0; i < progress.size(); i++)
			{
				curWeight += progress[i].second;
			}

			// 새로운 트럭의 무게를 구한다.
			int newWeight = truckQueue.front();

			// 새로운 트럭이 올라갈 수 있다면 추가한다.
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