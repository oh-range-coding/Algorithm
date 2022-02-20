#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//경과시간 : 12분

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> data;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		data.push_back(d);
	}

	sort(data.begin(),data.end());
	
	int result_value = 0;
	int isContinue=k;
	for (int i = 0; i < m; i++) {
		
		if (isContinue == 0) {
			isContinue = k;
			result_value += data[n - 2];
			
		}
		else {
			result_value += data[n - 1];
		}
		isContinue -= 1;
	}
	cout << "답은? " << result_value << endl;
	return 0;
}