#include<iostream>
#include <string>
#include <vector>

using namespace std;
//3Ка
int main() {

	string data;
	cin >> data;

	int mid = data.size() / 2;

	int left_sum = 0;
	int right_sum = 0;
	for (int i = 0; i < mid; i++) {
		left_sum += data[i]-'0';
	}
	for (int i = mid; i < data.size(); i++) {
		right_sum += data[i] - '0';
	}

	if (left_sum == right_sum) {
		cout << "LUCKY";
	}
	else {
		cout << "READY";
	}
	

	return 0;
}