#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int result = 0;
	int count = 0;

	for (auto i : arr)
	{
		count++;
		if (count >= i)
		{
			result++;
			count = 0;
		}
	}

	cout << result << '\n';

	return 0;
}