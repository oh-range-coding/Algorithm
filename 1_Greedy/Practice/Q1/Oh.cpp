#include <iostream>

using namespace std;

int main()
{
	int N, count = 0;

	int coin[] = { 500,100,50,10 };
	cin >> N;

	for (auto i : coin)
	{
		count += N / i;
		N %= i;
	}

	cout << count << '\n';

	return 0;
}