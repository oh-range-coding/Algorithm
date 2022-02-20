#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 28Ка
int main() {

	int n;
	cin >> n;

	vector<int> data;

	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		data.push_back(d);
	}

	
	sort(data.begin(), data.end(),greater<>());
	int max = -1;
	for (int a = 0; a < n - 1; a++) {
		int k = data[a] - 1;
		int result = 0;
		for (int i = a; i < n; i++) {
			if (k == 0) {
				result += 1;
				k = data[i] - 1;
			}
			else {
				k -= 1;
			}

		}
		if (result > max) {
			max = result;
		}
	}
	cout << max;




	return 0;
}