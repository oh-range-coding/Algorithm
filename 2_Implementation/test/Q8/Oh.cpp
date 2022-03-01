#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int num = 0;
	string result;
	for (auto c : s)
	{
		if (c >= '0' && c <= '9')
		{
			num += c - '0';
		}
		else
		{
			result += c;
		}
	}

	sort(result.begin(), result.end());
	result += to_string(num);

	cout << result;

	return 0;
}