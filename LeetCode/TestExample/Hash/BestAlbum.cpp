#include "../../stdafx.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

// 1. ��� ���� ���̵� �帣
// 2. �帣 ������ ����� ����
// 3. ������ ������ȣ �����ź���

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<string> orderedGenres;

	if (genres.size() == 0)
		return answer;

	// map<int, string, greater<int>> orderedGenresMap;
	// ��� ���� �帣 ���Ŀ뵵 
	vector<pair<int, string>> orderedGenreVec;

	// �帣���� �÷��� Ƚ��
	unordered_map<string, int> playsOfGenres;

	// �����, ������ȣ
	unordered_map<string, vector<pair<int, int>>> musicMap;

	// �帣���� �÷��� ���� ���� ��ȣ�� �����Ѵ�.

	for (int i = 0; i < plays.size(); i++)
	{
		musicMap[genres[i]].push_back(make_pair(plays[i], i));
		playsOfGenres[genres[i]] += plays[i];
	}

	// Ƚ���� �帣�� �����Ѵ�.
	for (auto genre : playsOfGenres)
	{
		orderedGenreVec.push_back(make_pair(genre.second, genre.first));
	}

	// ���Ƚ���� ������� �����Ѵ�.
	sort(orderedGenreVec.begin(), orderedGenreVec.end(), [](pair<int, string> a, pair<int, string >b) -> bool
	{
		return a.first > b.first;
	});

	// ���ĵ� �帣�� ������� �߰��Ѵ�.
	for (auto genre : orderedGenreVec)
	{
		if (find(orderedGenres.begin(), orderedGenres.end(), genre.second) == orderedGenres.end())
			orderedGenres.push_back(genre.second);
	}

	// �帣���� ��� ���� ���� ���� ��ȣ�� �����Ѵ�.
	for (auto& musicList : musicMap)
	{
		sort(musicList.second.begin(), musicList.second.end(), [](pair<int, int> a, pair<int, int> b)->bool
		{
			if (a.first == b.first)
				return a.second < b.second;
			return a.first > b.first;
		});
	}

	// ���ĵ� �帣 ������� ������ȣ�� �־��ش�.
	for (int i = 0; i < orderedGenres.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j >= musicMap[orderedGenres[i]].size())
				break;
			answer.push_back(musicMap[orderedGenres[i]][j].second);
		}
	}


	return answer;
}