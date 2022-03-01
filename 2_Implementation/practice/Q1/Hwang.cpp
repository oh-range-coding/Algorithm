#include <iostream>
#include <string>
using namespace std;

int main() {
	//L, R, U, D����
	//x�� ��, y�� ��
	int dr[4] = { 0, 0, -1, 1 };
	int dc[4] = { -1, 1, 0, 0 };
	char dir[4] = { 'L', 'R', 'U', 'D' };

	int n;
	cin >> n;
	cin.ignore(); //�ٹٲ� ���ڸ� �ν��ؼ� �ٷ� ó���ǹǷ� ���۸� ����� ���� ���� �ν��� �� ����
	string cmd;
	//���⸦ �����ϵ� �ٹٲ� ���� �����ϰ� ��°�� �� ���� �Է¹ޱ�(string ���)
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