#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	long long sum = 0;

	for (int i = 0; i < food_times.size(); i++)
	{
		sum += food_times[i];
	}
	if (sum < k)
		return -1;

	int min = *min_element(food_times.begin(), food_times.end());
	int min_index = min_element(food_times.begin(), food_times.end()) - food_times.begin();
	while (true)
	{
		if (min * food_times.size() < k)
		{
			k -= min * food_times.size();
			for (int i = 0; i < food_times.size(); i++)
			{
				food_times[i] -= min;
			}

			food_times.erase(food_times.begin() + min_index);

			min = *min_element(food_times.begin(), food_times.end());
			int min_index = min_element(food_times.begin(), food_times.end()) - food_times.begin();
		}
		else
		{
			break;
		}

	}

	answer = k % food_times.size() + 1;
	return answer;
}
