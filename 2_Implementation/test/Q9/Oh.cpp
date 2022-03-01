#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();	// 10

	for (int i = 1; i <= s.length() / 2; i++) // i = 1 2 3 4 5
	{
		int index = 0;
		string tmp;
		vector<string> arr;

		for (int j = 0; j < s.length() / i; j++)		// 10 5 3 2 2번
		{
			for (int k = 0; k < i; k++)	// 1 2 3 4 5 번
			{
				tmp += s[index++];
			}
			arr.push_back(tmp);
			tmp.clear();
		}

		int count = 1;
		string result;
		for (int j = 0; j < arr.size() - 1; j++)
		{
			if (arr[j] == arr[j + 1])
			{
				count++;
			}
			else
			{
				if (count != 1)
				{
					result += to_string(count) + arr[j];
					count = 1;
				}
				else
				{
					result += arr[j];
				}
			}
		}
		if (count != 1)
			result += to_string(count) + arr[arr.size() - 1];
		else
			result += arr[arr.size() - 1];

		for (int j = index; j < s.length(); j++)	// 나머지 붙이기
		{
			result += s[j];
		}

		if (result.length() < answer)
			answer = result.length();

		result.clear();
		arr.clear();
	}

	return answer;
}


int main()
{
	string s;
	cin >> s;

	cout << solution(s);

	return 0;
}