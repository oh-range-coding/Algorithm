#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	string s = to_string(N);

	int L = 0, R = 0;

	for (int i = 0; i < s.length() / 2; i++)
	{
		L += s[i];
		R += s[s.length() - i - 1];
	}

	if (L == R)
		cout << "LUCKY";
	else
		cout << "READY";

	return 0;
}