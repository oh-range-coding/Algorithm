#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;


//12분 -> 문제파악하느라 오래걸림 ㅡ.,ㅡ;;


int main() {

	int data[100][100];
	int n, m;
	cin >> n >> m;

	int t;
	vector<int> compare_result;
	for (int i = 0; i < n; i++) {
		int min_value = 10001;
		for (int j = 0; j < m; j++) {
			cin >> t;
			data[i][j] = t;
			if (min_value > t) {
				min_value = t;
			}
		}
		compare_result.push_back(min_value);
	}
	
	sort(compare_result.begin(), compare_result.end());

	cout << compare_result[compare_result.size()-1];
	




	return 0;
}