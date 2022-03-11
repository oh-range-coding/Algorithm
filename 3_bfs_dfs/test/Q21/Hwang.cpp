#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
int graph[51][51];
bool visited[51][51];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int main() {

	int n, r, c;
	cin >> n >> r >> c;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			int data;
			cin >> data;
			graph[i][j] = data;
		}
	}
	int result = 0;

	int social_num = 0;
	while (true) {
		for (int p = 0; p < n; p++)
		{
			for (int w = 0; w < n; w++) {

				visited[p][w] = false;

			}
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {

				if (visited[i][j] == false) {
					queue<pair<int, int>> q;
					q.push({ i,j });
					visited[i][j] = true;
					int sum_ = graph[i][j];
					int country_cnt = 1;
					vector<pair<int, int>> toApply_Country;
					toApply_Country.push_back({ i,j });
					while (!q.empty())
					{


						int r_, c_;
						tie(r_, c_) = q.front();
						q.pop();
						for (int k = 0; k < 4; k++) {
							int nr = r_ + dr[k];
							int nc = c_ + dc[k];
							if (0 <= nr && nr < n && 0 <= nc && nc < n && visited[nr][nc] == false) {
								int dif = abs(graph[r_][c_] - graph[nr][nc]);
								if (r <= dif && dif <= c) {
									visited[r_][c_] = true;
									visited[nr][nc] = true;

									sum_ += graph[nr][nc];
									country_cnt += 1;
									toApply_Country.push_back({ nr,nc });

									q.push({ nr,nc });

								}
							}
						}
					}
					if (country_cnt == 1) {
						count++;
					}
					for (auto value : toApply_Country) {
						graph[value.first][value.second] = (int)(sum_ / country_cnt);
					}

				}

			}

		}
		if (count == n * n) {
			break;
		}
		result += 1;
		
	}
	cout << result;



	return 0;
}
