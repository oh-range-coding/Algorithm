#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//6분. 공개수가 1000개까지라 이중 포문해도 100만번 돌꺼같은데
// 시간초과가 뜨는지는 모르겠네

int main() {

	int n, k;

	cin >> n >> k;

	vector<int> data;

	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		data.push_back(d);
	}

	int count = 0;
	for (int i = 0; i < n; i++) {

		for (int j = i+1; j < n; j++) {
			if (data[i] == data[j]) {
				continue;
			}
			else {
				count += 1;
			}
		}
	}
	cout << count;

	return 0;
}