#include "../../stdafx.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

// 1. 재생 제일 많이된 장르
// 2. 장르 내에서 재생된 순서
// 3. 같으면 고유번호 낮은거부터

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<string> orderedGenres;

	if (genres.size() == 0)
		return answer;

	// map<int, string, greater<int>> orderedGenresMap;
	// 재생 수로 장르 정렬용도 
	vector<pair<int, string>> orderedGenreVec;

	// 장르별로 플레이 횟수
	unordered_map<string, int> playsOfGenres;

	// 재생수, 고유번호
	unordered_map<string, vector<pair<int, int>>> musicMap;

	// 장르별로 플레이 수와 고유 번호를 저장한다.

	for (int i = 0; i < plays.size(); i++)
	{
		musicMap[genres[i]].push_back(make_pair(plays[i], i));
		playsOfGenres[genres[i]] += plays[i];
	}

	// 횟수와 장르를 저장한다.
	for (auto genre : playsOfGenres)
	{
		orderedGenreVec.push_back(make_pair(genre.second, genre.first));
	}

	// 재생횟수가 많은대로 정렬한다.
	sort(orderedGenreVec.begin(), orderedGenreVec.end(), [](pair<int, string> a, pair<int, string >b) -> bool
	{
		return a.first > b.first;
	});

	// 정렬된 장르를 순서대로 추가한다.
	for (auto genre : orderedGenreVec)
	{
		if (find(orderedGenres.begin(), orderedGenres.end(), genre.second) == orderedGenres.end())
			orderedGenres.push_back(genre.second);
	}

	// 장르별로 재생 수에 따라 고유 번호를 정렬한다.
	for (auto& musicList : musicMap)
	{
		sort(musicList.second.begin(), musicList.second.end(), [](pair<int, int> a, pair<int, int> b)->bool
		{
			if (a.first == b.first)
				return a.second < b.second;
			return a.first > b.first;
		});
	}

	// 정렬된 장르 순서대로 고유번호를 넣어준다.
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