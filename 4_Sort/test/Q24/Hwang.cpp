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
	cout << town[int((n - 1) / 2)];//중앙값을 고르면 되는 문제;
	
	

	return 0;
}