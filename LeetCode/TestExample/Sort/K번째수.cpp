#include "../../stdafx.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++)
	{
		int result = 0;
		vector<int> tempArray = array;
		sort(tempArray.begin() + (commands[i][0] - 1), tempArray.begin() + (commands[i][1]));
		result = *(tempArray.begin() + ((commands[i][0] - 1) + (commands[i][2] - 1)));
		answer.push_back(result);
	}
	return answer;
}