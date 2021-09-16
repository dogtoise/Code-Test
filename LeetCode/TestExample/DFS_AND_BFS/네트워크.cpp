#include "../../stdafx.h"

#include <string>
#include <vector>

using namespace std;


bool DFS(vector<vector<int>>& computers, int idx)
{
	if (computers[idx][idx] == 0)
		return false;
	computers[idx][idx] = 0;

	for (int i = 0; i < computers.size(); i++)
	{
		if (computers[idx][i])
			DFS(computers, i);
	}
	return true;
}


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (DFS(computers, i))
			answer++;
	}
	return answer;
}