#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	vector<int> town;
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		town.push_back(data);
	}
	sort(town.begin(), town.end());
	cout << town[int((n - 1) / 2)];//�߾Ӱ��� ���� �Ǵ� ����;
	
	

	return 0;
}