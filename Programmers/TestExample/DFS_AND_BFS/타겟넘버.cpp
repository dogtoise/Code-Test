#include "../../stdafx.h"

#include <string>
#include <vector>

using namespace std;

int g_answer = 0;


void DFS(vector<int> numbers, int target, int sum, int idx)
{
	if (numbers.size() <= idx)
	{
		if (sum == target)
		{
			g_answer++;
		}
		return;
	}

	DFS(numbers, target, sum + numbers[idx], idx + 1);
	DFS(numbers, target, sum - numbers[idx], idx + 1);
}
int solution(vector<int> numbers, int target) {
	int answer = 0;
	DFS(numbers, target, 0, 0);
	answer = g_answer;
	return answer;
}