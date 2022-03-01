#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int dx[4] = { 0,1,0,-1 };	// 상 우 하 좌
	int dy[4] = { -1,0,1,0 };	// 상 우 하 좌
	int d = 1;	// 처음 방향 오른쪽

	queue<pair<int, int>> q;

	int N, k, L;
	cin >> N >> k;

	vector<vector<int>> map(N, vector<int>(N, 0));

	for (int i = 0; i < k; i++)	//사과
	{
		int r, c;
		cin >> r >> c;
		map[r - 1][c - 1] = 1;
	}

	cin >> L;

	vector<int> sec(L);
	vector<char> dir(L);

	for (int i = 0; i < L; i++)
	{
		int X;
		char C;
		cin >> X >> C;
		sec[i] = X;
		dir[i] = C;
	}

	int time = 0;
	int i = 0;
	int R = 0, C = 0;	// 행 열
	map[R][C] = 2;
	while (true)
	{
		q.push(make_pair(R, C));

		int nr, nc;
		nr = R + dy[d % 4];
		nc = C + dx[d % 4];

		if (nr >= 0 && nr < N && nc >= 0 && nc < N)	//맵 안일 때
		{
			if (map[nr][nc] != 2)
			{
				C = nc;
				R = nr;

				time++;
				if (map[nr][nc] == 1)	// 다음칸이 사과일 때
				{
					map[nr][nc] = 2;
					continue;
				}
				else
				{
					map[q.front().first][q.front().second] = 0;	// 꼬리 지우기
					q.pop();
				}
				map[nr][nc] = 2;	// 방문한 칸 표시
			}
			else // 이미 방문한 칸이면
			{
				break;
			}
		}
		else // 맵 밖이면
		{
			break;
		}

		if (i < L)
		{
			if (time == sec[i])	// 입력된 시간과 같으면 방향 전환
			{
				if (dir[i] == 'D')	// 시계방향
				{
					d++;
				}
				else	// 반시계방향
				{
					d--;
				}
				i++;
			}
		}

	}

	cout << time + 1;

	return 0;
}