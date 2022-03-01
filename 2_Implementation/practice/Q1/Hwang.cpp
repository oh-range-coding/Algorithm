#include <iostream>
#include <string>
using namespace std;

int main() {
	//L, R, U, D순서
	//x는 행, y는 열
	int dr[4] = { 0, 0, -1, 1 };
	int dc[4] = { -1, 1, 0, 0 };
	char dir[4] = { 'L', 'R', 'U', 'D' };

	int n;
	cin >> n;
	cin.ignore(); //줄바꿈 문자를 인식해서 바로 처리되므로 버퍼를 비워야 다음 줄을 인식할 수 있음
	string cmd;
	//띄어쓰기를 포함하되 줄바꿈 문자 제외하고 통째로 한 줄을 입력받기(string 헤더)
	getline(cin, cmd);
	int r = 1; int c = 1;

	for (int i = 0; i < cmd.size(); i++) {
		int nr = 0; int nc = 0;
		for (int j = 0; j < 4; j++) {
			if (cmd[i] == dir[j]) {
				nr = r + dr[j];
				nc = c + dc[j];
			}
		}
		if (nr <1 || nc >n || nr <1 || nc >n) {
			continue;
		}
		else {
			r = nr;
			c = nc;
		}
	}
	cout << r << " " << c;
	return 0;
}