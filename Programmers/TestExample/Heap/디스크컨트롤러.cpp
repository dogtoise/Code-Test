#include "../../stdafx.h"

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


struct PriorityCompare
{
	bool operator()(vector<int> a, vector<int> b)
	{
		return a[0] > b[0];
	}
};
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	// ��û�ð�, �ҿ�ð�, ���� ��ȣ
	priority_queue<vector<int>, vector<vector<int>>, PriorityCompare> orderedJobs;
	vector<int> spendedTimes;
	vector<vector<int>> requests;
	vector<int> disk;
	disk.push_back(0);
	disk.push_back(0);
	disk.push_back(-1);
	int totalTime = 0;

	// ��û�ð��� ���� ����
	for (int i = 0; i < jobs.size(); i++)
	{
		vector<int> job;
		job.push_back(jobs[i][0]);
		job.push_back(jobs[i][1]);
		job.push_back(i);
		orderedJobs.push(job);
	}
	spendedTimes.resize(jobs.size());

	while (true)
	{
		vector<int> job;
		if (orderedJobs.size() != 0)
		{
			while (true)
			{
				if (orderedJobs.size() == 0)
					break;
				job = orderedJobs.top();
				// ��û�ð��� �Ǿ����� ��û ����Ʈ�� �߰��Ѵ�.
				if (job[0] <= totalTime)
				{
					requests.push_back(job);
					orderedJobs.pop();
				}
				else
					break;
			}
		}
		// ��ũ�� ����� ��� 
		if (disk[1] == 0)
		{
			if (orderedJobs.size() == 0 && requests.size() == 0)
			{
				break;
			}
			if (requests.size() == 1)
			{
				disk = requests[0];
				requests.clear();
			}
			else
			{
				int priorityIndex = -1;
				vector<int> priorityJob;
				int fastestTime = 100000;
				for (int j = 0; j < requests.size(); j++)
				{
					int temp = requests[j][1];
					if (fastestTime > temp)
					{
						fastestTime = temp;
						priorityJob = requests[j];
						priorityIndex = j;
					}
				}
				if (priorityIndex != -1)
				{
					requests.erase(requests.begin() + priorityIndex);
					disk = priorityJob;
				}
			}
		}


		int workTime = 0;
		if (disk[1] == 0)
		{
			workTime = orderedJobs.top()[0] - totalTime;
		}
		else if (orderedJobs.size() != 0)
		{
			workTime = orderedJobs.top()[0] - totalTime;
			if (workTime >= disk[1])
				workTime = disk[1];
			//workTime = disk[1];
		}
		else
		{
			workTime = disk[1];
		}


		// spend time ���
		if (disk[1] != 0)
		{
			spendedTimes[disk[2]] += workTime;
		}
		for (int j = 0; j < requests.size(); j++)
		{
			spendedTimes[requests[j][2]] += workTime;
		}

		// ��ũ �۾�
		if (disk[1] != 0)
			disk[1] -= workTime;

		totalTime += workTime;
	}

	for (int i = 0; i < spendedTimes.size(); i++)
	{
		answer += spendedTimes[i];
	}
	answer /= spendedTimes.size();

	return answer;
}