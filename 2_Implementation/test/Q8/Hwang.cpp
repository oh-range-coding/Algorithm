#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
//경과시간 5분내 : 시간 안쟀음 실수로..
int main() {

	string data;
	cin >> data;
	int num_sum = 0;
	vector<char> char_list;

	string result="";

	for (int i = 0; i < data.size(); i++) {
		if ('0' <= data[i] && data[i] <= '9') {
			num_sum += data[i] - '0';
		}
		else {
			char_list.push_back(data[i]);
		}
	}
	sort(char_list.begin(), char_list.end());

	for (int i = 0; i < char_list.size(); i++) {
		result += char_list[i];

	}
	result += to_string(num_sum);

	cout << result;

	return 0;
}