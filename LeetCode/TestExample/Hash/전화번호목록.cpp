#include "../../stdafx.h"

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	unordered_map<string, int> hashMap;
	for (string phoneNumber : phone_book)
	{
		for (int i = 0; i < phoneNumber.length() - 1; i++)
		{
			hashMap.insert(make_pair(phoneNumber.substr(0, i + 1), 1));
		}
	}

	for (string phoneNumber : phone_book)
	{
		if (hashMap[phoneNumber] == 1)
		{
			answer = false;
			break;
		}
	}

	return answer;
}