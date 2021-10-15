#include "../../stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	int count = 0;
	int begin = 0;
	int end = 1;

	sort(people.begin(), people.end());

	while (true)
	{
		// 제일 뒤에 무게를 넣기 (가장 무거운)
		int first = people[people.size() - end];
		end++;
		count++; // 한명 뺐다고 표시

				 // 최대제한에 제일 무거운 사람을 계산했을 때 가장 가벼운 사람이 탈 수 있다면
		if (limit - first >= people[begin])
		{
			// 앞사람 인덱스 증가와 보트에 탄 사람 추가
			begin++;
			count++;
		}
		// 보트 나간횟수 증가
		answer++;

		// 보트를 타고 나간사람이 총 인원보다 같거나 많아지면 반복문 종료
		if (count >= people.size()) break;
	}


	return answer;
}