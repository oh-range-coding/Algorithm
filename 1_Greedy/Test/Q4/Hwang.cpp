#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// 6�� Ǯ���� ����� ���� �ݹ� Ǯ���µ�, �Ƹ� ó�������� �����ɷ�����;
int main() {
	int n;
	cin >> n;

	vector<int> data;


	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		data.push_back(d);
	}
	sort(data.begin(), data.end());

	int min_value = 1;

	for (int i = 0; i < n; i++) {
		if (data[i] <= min_value) {
			min_value += data[i];
		}
		else {
			break;
		}
	}
	cout << min_value;

	return 0;
}