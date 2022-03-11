#include<iostream>
#include<vector>
#include<queue>

using namespace std;



vector<vector<int>> graph;
vector<vector<int>> dist_value;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string data;
		vector<int> tmp;
		cin >> data;
		for (int j = 0; j < data.size(); j++)
		{
			if (data[j] == '0') {
				tmp.push_back(0);
				

			}
			else if (data[j] == '1') {
				tmp.push_back(1);
				
			}
		}
		graph.push_back(tmp);
	}
	queue<pair<int, int>> player;
	player.push({ 0,0  });

	while (!player.empty()) {
		int r = player.front().first;
		int c = player.front().second;
		player.pop();
		
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (0 <= nr && nr < n && 0 <= nc && nc < m&&graph[nr][nc]==1) {

				graph[nr][nc] = graph[r][c] + 1;
				
				player.push({nr,nc});
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout <<graph[i][j] << " ";
		}cout << endl;
	}
	cout<<graph[n-1][m-1];
	


	return 0;
}