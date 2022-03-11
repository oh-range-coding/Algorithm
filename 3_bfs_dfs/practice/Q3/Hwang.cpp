#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
bool dfs(int r,int c) {
	int n = graph.size();
	int m = graph[0].size();
	if (r < 0 || r >= n || c < 0 || c >= m)
		return false;

	if (visited[r][c] == false) {
		visited[r][c] = true;
	}
	else {
		return false;
	}

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		dfs(nr, nc);
	}return true;
	
}

int main() {
	int n, m;
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string data;
		vector<int> tmp;
		vector<bool> tmp2;
		cin >> data;
		for (int j = 0; j < data.size(); j++) 
		{
			if (data[j] == '0') {
				tmp.push_back(0);
				tmp2.push_back(false);
				
			}
			else if (data[j] == '1') {
				tmp.push_back(1);
				tmp2.push_back(true);
			}
		}
		visited.push_back(tmp2);
		graph.push_back(tmp);

	
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j) == true) {
				count++;
			}
		}
	}
	cout << count;
	

	return 0;
}