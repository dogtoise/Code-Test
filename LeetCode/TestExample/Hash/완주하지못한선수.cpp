#include "../../stdafx.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> completionHashMap;
	for (string name : participant)
	{
		completionHashMap[name]++;
	}
	for (string name : completion)
	{
		completionHashMap[name] = completionHashMap[name] - 1;
	}
	for (string name : participant)
	{
		if (completionHashMap[name] == 1)
		{
			answer = name;
			break;
		}
	}

	return answer;
}