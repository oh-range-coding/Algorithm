#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

int Virus_Spread(vector<vector<int>> graph,vector<pair<int,int>> virus_list) {
    queue<pair<int, int>> q;
    int n = graph.size();
    int m = graph[0].size();
    for (int i = 0; i < virus_list.size(); i++) {
        int tmp_r = virus_list[i].first;
        int tmp_c = virus_list[i].second;
        q.push({ tmp_r,tmp_c });
    }
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }
            if (graph[nr][nc] == 0) {
                graph[nr][nc] = 2;
                q.push({ nr,nc });
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) {
                count += 1;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<vector<int>> graph(n);
    vector<pair<int, int>> empty_list;
    vector<pair<int, int>> virus_list;
    for (int i = 0; i < n;i++) {
        string data;
        
        getline(cin, data);

        for (int j = 0; j < data.size(); j++) {
            if (data[j] == ' ') {
                continue;
            }
            graph[i].push_back(data[j]-'0');
            
        }
        

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) {
                empty_list.push_back({ i,j });
            }
            else if (graph[i][j] == 2) {
                virus_list.push_back({ i,j });
            }
        }
    }
    int len = empty_list.size();
    int result = 0;
    vector<bool> v(len - 3, false);
    v.insert(v.end(), 3, true);
    int min_value = 1000000;
    do {
        vector<pair<int, int>> tmp;
        for (int k = 0; k < len; k++) {
            if (v[k]) tmp.push_back(empty_list[k] );
        }
        for (int i = 0; i < tmp.size(); i++) 
        {
            int tmp_r = tmp[i].first;
            int tmp_c = tmp[i].second;
            graph[tmp_r][tmp_c] = 1;
        }
        
        int tmp_result =Virus_Spread(graph,virus_list);
        if (tmp_result >= result) {
            result = tmp_result;
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            int tmp_r = tmp[i].first;
            int tmp_c = tmp[i].second;
            graph[tmp_r][tmp_c] = 0;
        }


    } while (next_permutation(v.begin(), v.end()));
    cout << result;
	return 0;
}