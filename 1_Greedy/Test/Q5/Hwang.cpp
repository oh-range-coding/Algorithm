#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//6��. �������� 1000�������� ���� �����ص� 100���� ����������
// �ð��ʰ��� �ߴ����� �𸣰ڳ�

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