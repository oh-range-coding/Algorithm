#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int A, B, dir;
	cin >> A >> B >> dir;

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int D[4] = { 0, 3, 2, 1 };

	int map[50][50];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	int count = 1;
	int flag = 0;

	while (flag < 4)
	{
		flag = 0;

		for (int i = 0; i < 4; i++)
		{

			int nx = 0, ny = 0;

			nx = B + dx[D[dir % 4]];
			ny = A + dy[D[dir % 4]];
			dir++;

			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				if (map[ny][nx] != 1)
				{
					map[ny][nx] = 1;
					A = ny;
					B = nx;
					count++;
				}
				else
					flag++;
			}
			else
				flag++;
		}
	}


	cout << count;

	return 0;
}