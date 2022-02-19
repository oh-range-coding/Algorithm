#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;
	int result = input[0] - '0';
	for (int i = 1; i < input.length(); i++)
	{
		if (result + input[i] - '0' > result * input[i] - '0')
			result += input[i] - '0';
		else
			result *= input[i] - '0';
	}

	cout << result << '\n';

	return 0;
}