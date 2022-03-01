#include<iostream>
#include <vector>
#include<deque>
using namespace std;

int main() {

	int n, k;
	int L;

	//            R  D  L  U
	int dr[4] = { 0 ,1, 0,-1 };
	int dc[4] = { 1, 0,-1, 0 };
	int state = 0;//¿ìÃø
	
	vector<pair<int, char>> direction_data;
	cin >> n;
	cin >> k;

	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i].push_back(0);
		}
	}

	for (int i = 0; i < k; i++) {
		int r,c;
		cin >> r >> c;
		graph[r - 1][c - 1] = -1; // 0 ºó°÷, 1 Áö··ÀÌ, -1 »ç°ú
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int t;
		char dir;
		cin >> t >> dir;
		direction_data.push_back(pair<int, char>(t, dir));
	}

	int game_time = 0;

	graph[0][0] = 1;
	
	
	int dir_idx=0;


	deque<pair<int, int>> snake;
	snake.push_back(make_pair(0, 0));
	

	
	
	while (true) {
		game_time++;
		
		int next_r = snake.front().first + dr[state];
		int next_c = snake.front().second + dc[state];
		if (next_c >= n || next_c < 0 || next_r >= n || next_r < 0||graph[next_r][next_c]==1) {
			break;
		}
		if (graph[next_r][next_c] == -1) {
			graph[next_r][next_c] = 1;
			snake.push_front(make_pair(next_r, next_c));

		}
		else if (graph[next_r][next_c] == 0) {
			graph[next_r][next_c] = 1;
			graph[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
			snake.push_front(make_pair(next_r, next_c));
		}

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < n; j++) {
		//		cout << graph[i][j] << " ";

		//	}cout << endl;
		//}


		//cout << "time : " << game_time << endl;
		if (direction_data[dir_idx].first == game_time) {


			if (direction_data[dir_idx].second == 'D') {
				state += 1;
			}
			else {
				state -= 1;
			}

			if (state < 0) {
				state = 3;
			}
			state %= 4;
			dir_idx += 1;
			if (dir_idx >= direction_data.size() - 1) {
				dir_idx = direction_data.size() - 1;
			}
		}
		
		
	}
	cout << game_time;

	return 0;
}