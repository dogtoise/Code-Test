#include "../../stdafx.h"
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	// 필요한 글자수만큼 반복하기
	for (int j = 0, index = -1; j < number.length() - k; j++)
	{
		char max = 0;
		// 앞에서 남겨야 되는 숫자 중에 제일 큰 수 
		for (int i = index + 1; i <= k + j; i++)
		{
			if (max < number[i])
			{
				index = i;
				max = number[i];
			}
		}
		answer += max;
	}
	return answer;
}