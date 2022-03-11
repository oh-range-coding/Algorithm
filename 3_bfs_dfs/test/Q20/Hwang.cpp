#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
bool Check_Avoid(int r, int c, int dir, vector<vector<char>> graph) {

	int n = graph.size();
	if (r < 0 || r >= n || c < 0 || c >= n) {
		return true;
	}
	if (graph[r][c] == 'T') {
		return false;
	}
	else if (graph[r][c] == 'O' || graph[r][c] == 'S') {
		return true;
	}
	int nr = r + dr[dir];
	int nc = c + dc[dir];
	if (Check_Avoid(nr, nc, dir, graph) == false) {
		return false;

	}
	return true;


}

int main() {
	int n;
	cin >> n;
	vector<vector<char>> graph(n);
	vector<pair<int, int>> empty_pos;
	vector<pair<int, int>> student_pos;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string data;
		getline(cin, data, '\n');
		for (int j = 0; j < data.size(); j++) {
			if (data[j] != ' ') {
				graph[i].push_back(data[j]);
			}
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 'X') {
				empty_pos.push_back({ i,j });
			}
			else if (graph[i][j] == 'S') {
				student_pos.push_back({ i,j });
			}
		}
	}


	int len = empty_pos.size();
	vector<bool> v(len - 3, false);
	v.insert(v.end(), 3, true);
	string answer = "";
	int min_value = 1000000;
	do {
		vector<pair<int, int>> tmp;
		for (int k = 0; k < len; k++) {
			if (v[k]) tmp.push_back(empty_pos[k]);
		}
		for (int i = 0; i < tmp.size(); i++) {
			int r_, c_;
			r_ = tmp[i].first;
			c_ = tmp[i].second;
			graph[r_][c_] = 'O';
		}
		int count = 0;
		for (int i = 0; i < student_pos.size(); i++) {
			int r_, c_;
			r_ = student_pos[i].first;
			c_ = student_pos[i].second;
			int near_count = 0;
			for (int j = 0; j < 4; j++) {
				int nr_ = r_ + dr[j];
				int nc_ = c_ + dc[j];
				if (Check_Avoid(nr_, nc_, j, graph)) {
					near_count += 1;
				}
			}
			if (near_count == 4) {
				count += 1;
			}
		}
		if (count == student_pos.size()) {
			answer = "YES";
			break;
		}
		else {
			answer = "NO";
		}

		for (int i = 0; i < tmp.size(); i++) {
			int r_, c_;
			r_ = tmp[i].first;
			c_ = tmp[i].second;
			graph[r_][c_] = 'X';
		}



	} while (next_permutation(v.begin(), v.end()));

	cout << answer;
	return 0;
}
