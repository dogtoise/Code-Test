#include "../../stdafx.h"

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
* Complete the 'hourglassSum' function below.
*
* The function is expected to return an INTEGER.
* The function accepts 2D_INTEGER_ARRAY arr as parameter.
*/

int hourglassSum(vector<vector<int>> arr) {

	int answer = -1000000;
	for (int i = 1; i < arr.size() - 1; i++)
	{
		for (int j = 1; j < arr[i].size() - 1; j++)
		{
			int sum = 0;
			sum += arr[i - 1][j - 1];
			sum += arr[i - 1][j];
			sum += arr[i - 1][j + 1];
			sum += arr[i][j];
			sum += arr[i + 1][j - 1];
			sum += arr[i + 1][j];
			sum += arr[i + 1][j + 1];

			if (sum > answer)
				answer = sum;
		}
	}
	return answer;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	vector<vector<int>> arr(6);

	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);

		string arr_row_temp_temp;
		getline(cin, arr_row_temp_temp);

		vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

		for (int j = 0; j < 6; j++) {
			int arr_row_item = stoi(arr_row_temp[j]);

			arr[i][j] = arr_row_item;
		}
	}

	int result = hourglassSum(arr);

	fout << result << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
