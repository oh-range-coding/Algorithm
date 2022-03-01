#include <iostream>
using namespace std;

int move_possible[8][2]{
	{1, -2}, {2, -1}, {2, 1}, {1, 2},
	{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};

bool isCheck(int r, int c, int num) {
	int nr = r + move_possible[num][0];
	int nc = c + move_possible[num][1];

	return ((1 <= nr && nr <= 8) && (1 <= nc && nc <= 8));
}

int main() {
	string start_pos;	
	cin >> start_pos;
	
	int r = start_pos[0] - 'a' + 1;
	int c = start_pos[1] - '1' + 1;
	

	int result = 0;
	for (int i = 0; i < 8; ++i)	// 8방향 모두 테스트
		if (isCheck(r, c, i))
			result += 1;
	cout << result;
}