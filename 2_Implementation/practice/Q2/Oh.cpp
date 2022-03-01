#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int count = 0;

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				string time = to_string(i) + to_string(j) + to_string(k);
				if (time.find("3") != string::npos)
				{
					count++;
				}
			}
		}
	}
	cout << count;

	return 0;
}