#include "../../stdafx.h"

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;


	priority_queue<int, vector<int>, greater<int>> orderedScovilles;
	for (int i = 0; i < scoville.size(); i++)
	{
		orderedScovilles.push(scoville[i]);
	}
	if (orderedScovilles.top() >= K)
	{
		return 0;
	}

	int tryCount = 0;
	while (!orderedScovilles.empty())
	{
		if (orderedScovilles.size() < 2 && orderedScovilles.top() < K)
		{
			return -1;
		}
		tryCount++;

		int lowestFood = orderedScovilles.top();
		orderedScovilles.pop();
		int secondFood = orderedScovilles.top();
		orderedScovilles.pop();

		int newScoville = lowestFood + (secondFood * 2);
		orderedScovilles.push(newScoville);

		if (orderedScovilles.top() >= K)
		{
			answer = tryCount;
			break;
		}
	}

	return answer;
}