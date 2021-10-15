#include "../../stdafx.h"
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int GetBasicNumber(int n, int cnt)
{
	int res = 0;
	while (cnt > 0)
	{
		cnt -= 1;
		res += n * pow(10, cnt);
	}
	return res;
}

int solution(int N, int number) {
	int answer = -1;

	if (N == number)
		return 1;

	const int MIN = 8;
	vector<set<int>> sets;
	sets.resize(MIN);

	// 각 set마다 기본 수 "N" * i 수 초기화
	for (int i = 0; i < MIN; i++)
	{
		sets[i].insert(GetBasicNumber(N, i + 1));
	}


	for (int i = 1; i < MIN; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (const auto& op1 : sets[j])
			{
				for (const auto& op2 : sets[i - j - 1])
				{
					sets[i].insert(op1 + op2);
					sets[i].insert(op1 - op2);
					sets[i].insert(op1 * op2);

					if (op2 != 0)
						sets[i].insert(op1 / op2);
				}
			}
		}
		// 셋 중 찾는 숫자가 있는 경우
		if (sets[i].find(number) != sets[i].end())
		{
			answer = i + 1;
			break;
		}
	}

	return answer;
}