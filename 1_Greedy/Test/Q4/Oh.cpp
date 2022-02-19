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

	int result = 1;
	for (auto i : arr)
	{
		if (result < i)
			break;
		result += i;
	}

	cout << result << '\n';

	return 0;
}