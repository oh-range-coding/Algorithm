#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	vector<vector<int>> graph(n+1);
	cin.ignore();
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start>>end;
		graph[start - 1].push_back(end-1);
	}

	vector<int> dist_graph;
	for (int i = 0; i < n; i++) {
		dist_graph.push_back(100000);

	}


	queue<int> q;
	q.push(x-1);
	dist_graph[x - 1] = 0;
	
	while (!q.empty()) {
		int cur_city = q.front();
		
		q.pop();
		for (int i = 0; i < graph[cur_city].size(); i++) {
			if (dist_graph[graph[cur_city][i]] >= dist_graph[cur_city] + 1) {
				
				dist_graph[graph[cur_city][i]] = dist_graph[cur_city] + 1;
				q.push(graph[cur_city][i]);
			}
			
		}
	}
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		if (dist_graph[i] == k) {
			answer.push_back(i+1);
		}
	}
	if (answer.size() == 0) {
		cout << -1;
		return 0;
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}