#include "../../stdafx.h"

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	// index, price
	queue<pair<int, int>> priceQueue;

	for (int i = 0; i < prices.size(); i++)
	{
		priceQueue.push(make_pair(i, prices[i]));
	}
	while (!priceQueue.empty())
	{
		pair<int, int> price = priceQueue.front();
		priceQueue.pop();

		int second = 0;
		for (int i = price.first + 1; i < prices.size(); i++)
		{
			second++;
			if (price.second > prices[i])
			{
				break;
			}
		}
		answer.push_back(second);
	}

	return answer;
}