#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//20분 아이디어는 금방했는데 뭔가 꼬였음 ㅋㅋ;
int main() {

	string str;
	cin >> str;

	int zero_count = 0;
	int one_count = 0;

	char prevState = str[0];

	if (str.length() > 1) {

		for (int i = 1; i < str.length(); i++) {
			if (prevState != str[i]) {
				if (prevState == '0') {
					zero_count += 1;
					prevState = '1';
				}
				else {
					one_count += 1;
					prevState = '0';
				}
			}
		}



	}
	if (prevState == '0') {
		zero_count += 1;
	}
	else {
		one_count += 1;
	}

	int result = one_count <= zero_count ? one_count : zero_count;
	cout << result;




	/*bool zeroState=false;
	bool oneState=false;
	for (int i = 0; i < str.length(); i++) {
		if (zeroState==false&&str[i] == '0') {
			zeroState = true;
		}
		else if (oneState == false && str[i] == '1') {
			oneState = true;
		}
		else if(zeroState&&str[i]=='1'){
			zero_count += 1;
			zeroState = false;
			oneState = true;
		}
		else if (oneState && str[i] == '0') {
			one_count += 1;
			zeroState = true;
			oneState = false;
		}
		cout << zeroState << " ";
	}
	cout << endl;
	if (zeroState == true) {
		zero_count += 1;
	}
	else if (oneState) {
		one_count += 1;
	}
	cout << zeroState<<zero_count<<endl;
	cout << oneState<<one_count<<endl;
	int result = one_count <= zero_count ? one_count : zero_count;
	cout << result;*/


	
	return 0;
}