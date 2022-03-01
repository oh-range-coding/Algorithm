#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 60; j++) {
			for (int l = 0; l < 60; l++) {
				if (i / 10 == 0) {
					s += "0";
				}
				s += to_string(i);
				if (j / 10 == 0) {
					s += "0";
				}
				s += to_string(j);
				if (l / 10 == 0) {
					s += "0";
				}
				s += to_string(l);
				if (s.find(to_string(3)) != -1) {
					cnt++;
				}
				s.clear();
			}
		}
	}
	cout << cnt;

	return 0;
}