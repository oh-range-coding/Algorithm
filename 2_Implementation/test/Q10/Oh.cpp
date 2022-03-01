#include <string>
#include <vector>

using namespace std;

void Rotate(vector<vector<int>> &arr)
{
	int n = arr.size();
	vector<vector<int>> rotated_arr(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			rotated_arr[j][n - 1 - i] = arr[i][j];
		}
	}

	arr = rotated_arr;
}

bool Check(vector<vector<int>> large_lock)
{
	int n = large_lock.size() / 3;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (large_lock[i + n][j + n] != 1)
			{
				return false;
			}
		}
	}

	return true;
}

bool KeyIn(vector<vector<int>> key, vector<vector<int>> large_lock)
{
	vector<vector<int>> tmp(large_lock);
	int n = large_lock.size();
	int m = key.size();

	for (int i = 0; i <= n - m; i++)
	{
		for (int j = 0; j <= n - m; j++)	// key 대조
		{
			for (int k = 0; k < m; k++)
			{
				for (int l = 0; l < m; l++)
				{
					tmp[i + k][j + l] += key[k][l];
				}
			}

			if (Check(tmp))
				return true;

			tmp = large_lock;
		}
	}

	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int n = lock.size();
	vector<vector<int>> large_lock(n * 3, vector<int>(n * 3, 0));

	for (int i = 0; i < n; i++)	//큰 자물쇠 정의
	{
		for (int j = 0; j < n; j++)
		{
			large_lock[i + n][j + n] = lock[i][j];
		}
	}

	for (int u = 0; u < 4; u++)
	{
		if (KeyIn(key, large_lock))
			return true;

		Rotate(key);
	}


	return false;
}