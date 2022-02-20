#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;


//경과시간 : 2분

int main() {
	int count = 0;

	int n, k;
	cin >> n >> k;

	while (true) {

		if (n == 1) {
			break;
		}

		if (n % k == 0) {
			n /= k;
		}
		else {
			n -= 1;
		}
		count+=1;


	}
	cout << count;


	return 0;
}