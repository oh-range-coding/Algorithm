#include <iostream>
using namespace std;

int main() {
	int n, m, cur_r, cur_c, cur_dir;
	int graph[51][51];	// 0: 육지, 1: 바다, 2: 방문
	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,1,-1 };
	cin >> n >> m;
	cin >> cur_r >> cur_c >> cur_dir;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> graph[i][j];
	

	int result = 1;
	graph[cur_r][cur_c] = 2;

	while (true) {
		int turn_count = 0;
		for (int i = 0; i < 4; ++i) {
			cur_dir = cur_dir - 1;
			if (cur_dir < 0) {
				cur_dir = 3;
			}
				
			
			int next_r = cur_r + dr[cur_dir];
			int next_c = cur_c + dc[cur_dir];
			if (graph[next_r][next_c] == 0) {
				graph[next_r][next_c] = 2;
				cur_r = next_r;
				cur_c = next_c;
				result+=1;
				break;
			}
			else 
				turn_count++;	// 갈 수 없다면 방향만 바꾸고 턴 카운트 하나 증가.
		}
		if (turn_count == 4) {	// 더 이상 갈 곳이 없다면 뒤로 이동.
			cur_r = cur_r - dr[cur_dir];
			cur_c = cur_c - dc[cur_dir];
			// 뒷칸이 바다일 경우 더 이상 이동할 수 없으므로 종료.
			if (graph[cur_r][cur_c] ==1) 
				break;
			continue;
		}
	}
	cout << result;

}