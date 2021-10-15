#include "../../stdafx.h"
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int height;
	int dynamic[501][501];
	answer = triangle[0][0];
	dynamic[0][0] = triangle[0][0];

	height = triangle.size();

	for (int i = 1; i < height; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			// 1) 삼각형 제일 왼쪽 끝인 경우
			if (j == 0)
				dynamic[i][j] = dynamic[i - 1][j] + triangle[i][j];
			// 2) 삼각형 제일 오른쪽 끝인 경우
			else if (j == i)
			{
				dynamic[i][j] = dynamic[i - 1][j - 1] + triangle[i][j];
			}
			// 3) 삼각형 왼쪽, 오른쪽 끝이 아닌 내부인 경우
			else
			{
				dynamic[i][j] = max(dynamic[i - 1][j - 1], dynamic[i - 1][j]) + triangle[i][j];
			}

			answer = max(answer, dynamic[i][j]);
		}
	}

	return answer;
}