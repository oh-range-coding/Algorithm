#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	/*
	vector<vector<int>> card(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			card[i].push_back(a);
		}
	}
	*/

	vector<vector<int>> card(N, vector<int>(M));
	int min_max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			card[i][j] = a;
		}

		if (min_max < *min_element(card[i].begin(), card[i].end()))
		{
			min_max = *min_element(card[i].begin(), card[i].end());
		}
	}

	cout << min_max;

	return 0;
}