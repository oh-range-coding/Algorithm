#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, K, result = 0;
	cin >> N >> M >> K;

	vector<int> num(N);

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	sort(num.begin(), num.end(), greater<>());

	while (M)
	{
		for (int i = 0; i < K; i++)
		{
			result += num[0];
			M--;
		}
		result += num[1];
		M--;
	}

	cout << result << '\n';

	return 0;
}