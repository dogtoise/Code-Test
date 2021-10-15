#include "../../stdafx.h"

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


bool Compare(const string& a, const string& b)
{
	int wrong = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
		{
			wrong++;
			if (wrong >= 2)
			{
				return false;
			}
		}
	}
	return true;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	if (begin == target)
		return 0;

	bool bFound = false;
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == target)
		{
			bFound = true;
			break;
		}
	}
	if (bFound == false)
		return 0;

	// 문자, 시도횟수
	queue<pair<string, int>> que;

	que.push(make_pair(begin, 0));

	while (!que.empty())
	{
		string word = que.front().first;
		int curDepth = que.front().second;
		que.pop();

		if (word == target)
		{
			answer = curDepth;
			break;
		}

		for (int i = 0; i < words.size(); i++)
		{
			if (Compare(word, words[i]))
			{
				que.push(make_pair(words[i], curDepth + 1));
			}
		}

	}

	return answer;
}