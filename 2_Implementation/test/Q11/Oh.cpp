#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int dx[4] = { 0,1,0,-1 };	// �� �� �� ��
	int dy[4] = { -1,0,1,0 };	// �� �� �� ��
	int d = 1;	// ó�� ���� ������

	queue<pair<int, int>> q;

	int N, k, L;
	cin >> N >> k;

	vector<vector<int>> map(N, vector<int>(N, 0));

	for (int i = 0; i < k; i++)	//���
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
	int R = 0, C = 0;	// �� ��
	map[R][C] = 2;
	while (true)
	{
		q.push(make_pair(R, C));

		int nr, nc;
		nr = R + dy[d % 4];
		nc = C + dx[d % 4];

		if (nr >= 0 && nr < N && nc >= 0 && nc < N)	//�� ���� ��
		{
			if (map[nr][nc] != 2)
			{
				C = nc;
				R = nr;

				time++;
				if (map[nr][nc] == 1)	// ����ĭ�� ����� ��
				{
					map[nr][nc] = 2;
					continue;
				}
				else
				{
					map[q.front().first][q.front().second] = 0;	// ���� �����
					q.pop();
				}
				map[nr][nc] = 2;	// �湮�� ĭ ǥ��
			}
			else // �̹� �湮�� ĭ�̸�
			{
				break;
			}
		}
		else // �� ���̸�
		{
			break;
		}

		if (i < L)
		{
			if (time == sec[i])	// �Էµ� �ð��� ������ ���� ��ȯ
			{
				if (dir[i] == 'D')	// �ð����
				{
					d++;
				}
				else	// �ݽð����
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