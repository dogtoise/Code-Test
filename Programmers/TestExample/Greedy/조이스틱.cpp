#include "../../stdafx.h"
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
	int answer = 0;
	int len = name.length();

	int min = len - 1;

	for (int i = 0; i < len; i++)
	{
		// 조이스틱 상, 하 이동
		char c = name[i];

		int mov = (c - 'A' < 'Z' - c + 1) ? (c - 'A') : ('Z' - c + 1);
		answer += mov;

		// 조이스틱 좌, 우 이동
		int nextIndex = i + 1;
		// 다음 단어가 A이고, 단어가 끝나기 전까지 nextIndex 증가
		while (nextIndex < len && name[nextIndex] == 'A')
			nextIndex++;

		min = std::min(min, (i * 2) + len - nextIndex);
	}
	answer += min;
	return answer;
}