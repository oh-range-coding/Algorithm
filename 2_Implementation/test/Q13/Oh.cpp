#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int map[50][50] = { 0 };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	vector<pair<int, int>> chicken;

	int numC = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 2)
			{
				chicken.push_back(make_pair(i, j));
				numC++;
			}
		}
	}

	vector<int> v;
	vector<int> tmp(M, 1);

	for (int i = 0; i < numC; i++)
	{
		v.push_back(i);
	}

	for (int i = 0; i < numC - M; i++)
	{
		tmp.push_back(0);
	}

	sort(tmp.begin(), tmp.end());

	vector<int> Min;


	do
	{
		int sum = 0;

		for (int k = 0; k < N; k++)
		{
			for (int l = 0; l < N; l++)
			{
				if (map[k][l] == 1)
				{
					int min = 100;


					for (int i = 0; i < tmp.size(); i++)	//а╤гу
					{
						if (tmp[i] == 1)
						{
							if (min > abs(chicken[v[i]].first - k) + abs(chicken[v[i]].second - l))
								min = abs(chicken[v[i]].first - k) + abs(chicken[v[i]].second - l);

						}
					}

					sum += min;

				}
			}
		}


		Min.push_back(sum);

	} while (next_permutation(tmp.begin(), tmp.end()));

	cout << *min_element(Min.begin(), Min.end());

	return 0;
}