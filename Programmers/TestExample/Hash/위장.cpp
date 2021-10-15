#include "../../stdafx.h"

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	unordered_map<string, int> hashMap;
	// ¿Ã∏ß
	for (int i = 0; i < clothes.size(); i++)
	{
		//answer++;
		hashMap[clothes[i][1]]++;
	}

	int temp = 0;
	for (auto num : hashMap)
	{
		if (temp == 0)
			temp = num.second + 1;
		else
			temp *= (num.second + 1);
	}
	answer += temp;


	return answer - 1;
}