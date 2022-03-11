#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	cin.ignore();
	vector<vector<int>> graph(n);
	queue<tuple<int, int, int>> q;
	
	//vector<tuple<int,int,int>> virus_list;
	int dr[4] = { 0,0,1,-1 };
	int dc[4] = { 1,-1,0,0 };
	
	int data[201];


	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++) {
			cin >> data[j];
			graph[i].push_back(data[j]);
		}
	}


	for (int a = 1; a <= k; a++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] == a) {
					q.push({ 0,i,j });
				}
			}
		}
	}
	//¹«ÁË À§¿£/////


	//sort(virus_list.begin(), virus_list.end());
	int s, x, y;
	cin >> s >> x >> y;
	
	//for (int i = 0; i < virus_list.size(); i++) {
	//	int t, r, c;
	//	tie(t, r, c) = virus_list[i];
	//	q.push({ 0,r,c});
	//}
	while (!q.empty()) {
		int time, cr, cc;
		tie(time, cr, cc) = q.front();
		q.pop();
		if (time == s) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
				continue;
			}
			if (graph[nr][nc] == 0) {
				graph[nr][nc] = graph[cr][cc];
				q.push({ time + 1,nr,nc });
			}
		}
	}

	cout << graph[x - 1][y - 1];
	return 0;
}