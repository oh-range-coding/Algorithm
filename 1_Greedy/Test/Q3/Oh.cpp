#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;

	int count0 = 0;
	int count1 = 0;
	for (int i = 0; i < input.length() - 1; i++)
	{
		if (input[i] != input[i + 1])
		{
			if (input[i + 1] == '0')
				count0++;
			else
				count1++;
		}
	}
	int result = (count0 < count1 ? count0 : count1);
	cout << result;
	return 0;
}