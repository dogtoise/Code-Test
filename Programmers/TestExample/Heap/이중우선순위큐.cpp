#include "../../stdafx.h"

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <functional>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int, vector<int>, greater<int>> greaterQueue;
	priority_queue<int, vector<int>, less<int>> lessQueue;

	int totalSize = 0;
	for (string operation : operations)
	{
		if (operation.find("I") != string::npos) // I, ª¿‘
		{
			int number = 0;
			if (operation.find("-") != string::npos)
			{
				string numStr = operation.substr(3);
				number = stoi(numStr);
				number *= -1;
			}
			else
			{
				string numStr = operation.substr(2);
				number = stoi(numStr);
			}

			greaterQueue.push(number);
			lessQueue.push(number);
			totalSize++;
		}
		else // D, ªË¡¶
		{
			if (greaterQueue.size() == 0)
				continue;
			if (totalSize == 0)
				continue;
			int greaterValue = greaterQueue.top();
			int lessValue = lessQueue.top();
			if (lessValue < greaterValue)
			{
				// ∫Û∞¯∞£
				continue;
			}

			if (operation.find("-") == string::npos) // √÷¥Ò∞™ ªË¡¶
			{
				lessQueue.pop();
			}
			else // √÷º⁄∞™ ªË¡¶
			{
				greaterQueue.pop();
			}
			totalSize--;

			if (totalSize == 0)
			{
				while (!lessQueue.empty())
					lessQueue.pop();
				while (!greaterQueue.empty())
					greaterQueue.pop();
			}
		}
	}
	if (totalSize == 0)
	{
		answer.push_back(0);
		answer.push_back(0);
	}
	else
	{
		answer.push_back(lessQueue.top());
		answer.push_back(greaterQueue.top());
	}

	return answer;
}