#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//5Ка
int main() {
	char str[50];
	cin >> str;
	
	int result = str[0] - '0';
	
	for (int i = 1; i < strlen(str); i++) {
		if (str[i-1] - '0' == 0) {
			result += str[i]-'0';
		}
		else {
			result *= str[i] - '0';
		}
	}
	cout << result;

	return 0;
}