#include<iostream>
#include<vector>
#include<string>

using namespace std;
bool check_balance(string data);
string solution(string data) {
	if (data == "") {
		return "";
	}
	int n = data.size();
	int left_count = 0;
	int right_count = 0;
	int div_index=0;
	
	for (int i = 0; i < n; i++) {
		if (data[i] == '(') {
			left_count +=1;
		}
		else {
			right_count += 1;
		}
		if (left_count >= 1 && right_count >= 1 && left_count == right_count) {
			div_index = i;
			break;
		}
	}
	string u = "";
	string v = "";

	for (int i = 0; i <= div_index; i++) {
		u += data[i];
	}
	for (int i = div_index + 1; i < n; i++) {
		v += data[i];
	}
	if (check_balance(u)) {
		return u + solution(v);

	}
	else {
		
		string tmp="("+ solution(v)+")";
		
		for (int i = 0; i <u.size(); i++) {
			if (i == 0 || i == u.size()-1) {
				continue;
			}
			if (data[i] == ')') {
				tmp += "(";
			}
			else {
				tmp += ")";
			}
		}
		return tmp;
	}
	
}
bool check_balance(string data) {
	char check='a';
	int n = data.size();
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (check == 'a') {
			check = data[i];
		}
		else if (check == '(') {
			count += 1;
			check = data[i];
		}
		else if (check == ')') {
			count -= 1;
			check = data[i];
		}
		if (count <= -1) {
			return false;
		}
	}

	return true;
}

int main() {
	string data;

	cin >> data;
	cout<< solution(data);

	return 0;
}