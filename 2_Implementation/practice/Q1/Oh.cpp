#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	cin.ignore();	// 버퍼 비우기

	string s;
	getline(cin, s);

	char dir[4] = { 'U','D','L','R' };
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	int row = 1, col = 1;

	for (auto c : s)
	{
		int nx = 0, ny = 0;
		for (int i = 0; i < 4; i++)
		{
			if (c == dir[i])
			{
				nx = col + dx[i];
				ny = row + dy[i];
				break;
			}
		}
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
		{
			col = nx;
			row = ny;
		}
	}

	cout << row << ' ' << col;

	return 0;
}