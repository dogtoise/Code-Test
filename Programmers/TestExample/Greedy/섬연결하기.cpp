#include "../../stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 가중치에 따른 오름차순 정렬을 위한 비교
bool Cmp(vector<int> a, vector<int> b)
{
	return a[2] < b[2];
}

// 부모노드 찾기
int GetParent(vector<int>& parent, int x)
{
	// 부모노드가 자신이라면 자신을 리턴한다.
	if (parent[x] == x) return x;
	// 부모노드가 아니라면 최상위 부모노드 찾기
	return parent[x] = GetParent(parent, parent[x]);
}

// 부모노드 병합하기
void UnionParent(vector<int>& parent, int a, int b)
{
	// 두개의 부모를 가져와서
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	// 작은 노드쪽의 부모로 병합시키기
	a < b ? parent[b] = a : parent[a] = b;
}

// 부모노드가 같은지 비교
bool Find(vector<int> parent, int a, int b)
{
	// 부모노드를 가져와서
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	// 비교내용 리턴, 사이클 방지용
	return a == b;
}


int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int max = 0;

	// 가중치 기준으로 정렬
	sort(costs.begin(), costs.end(), Cmp);

	// costs를 순회해서 제일 높은 노드 찾기
	for (auto a : costs)
	{
		if (max < a[1]) max = a[1];
	}

	// 부모노드용 리스트 생성
	vector<int> parent;
	for (int i = 0; i <= max; i++)
	{
		parent.push_back(i); // 각 노드
	}

	// 코스트를 처음부터 순회
	for (auto a : costs)
	{
		if (!Find(parent, a[0], a[1]))
		{
			answer += a[2];
			UnionParent(parent, a[0], a[1]);
		}
	}


	return answer;
}