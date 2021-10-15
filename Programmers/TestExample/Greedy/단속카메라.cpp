#include "../../stdafx.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 0;

	// 들어온 리스트 정렬
	sort(routes.begin(), routes.end());

	// 비교를 위해 처음 차가 나가는 부분을 체크
	int temp = routes[0][1];

	for (auto a : routes)
	{
		// 현재 차가 나가는 부분보다 뒤에 차가 들어온다면
		if (temp < a[0])
		{
			// 카메라 설치
			answer++;
			// 나가는 부분 최신화
			temp = a[1];
		}

		// 현재 차보다 뒤 차가 먼저 나가면
		if (temp >= a[1])
			temp = a[1];
	}

	// 마지막 카메라 한대 추가
	return answer + 1;
}