#include <iostream>
#include <string>

using namespace std;

int main()
{
	char alph[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	char num[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };

	int dx[8] = { -1, -1, -2, -2, 1, 1, 2, 2 };
	int dy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };

	string s;
	cin >> s;

	int row = 0, col = 0;

	for (int i = 0; i < 8; i++)
	{
		if (s[0] == alph[i])
		{
			col = i;
		}
		if (s[1] == num[i])
		{
			row = i;
		}
	}

	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		int nx = 0, ny = 0;

		nx = col + dx[i];
		ny = row + dy[i];

		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
		{
			count++;
		}
	}

	cout << count;

	return 0;
}