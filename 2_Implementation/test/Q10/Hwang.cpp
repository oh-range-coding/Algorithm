#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<vector<int>> Rotate(vector<vector<int>> vv, int key_len);
bool Answer_Check(vector<vector<int>> gr, int lock_len);

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int lock_len = lock[0].size();
    int key_len = key[0].size();



    vector<vector<int>> graph(lock_len * 3);
    for (int i = 0; i < lock_len * 3; i++) {
        for (int j = 0; j < lock_len * 3; j++) {
            graph[i].push_back(0);
        }
    }
    for (int i = lock_len; i < lock_len * 2; i++) {
        for (int j = lock_len; j < lock_len * 2; j++) {
            graph[i][j] = lock[i - lock_len][j - lock_len];
        }
    }

    int first_count = 0;
    for (int i = 0; i < lock_len; i++) {
        for (int j = 0; j < lock_len; j++) {
            if (lock[i][j] == 1) {
                first_count += 1;
            }
        }
    }
    if (first_count == lock_len * lock_len) {
        return true;
    }

    for (int r = 0; r < 4; r++) {
        key = Rotate(key, key_len);
        for (int i = 0; i < lock_len * 3 - key_len; i++) {
            for (int j = 0; j < lock_len * 3 - key_len; j++) {


                for (int p = 0; p < key_len; p++) {
                    for (int q = 0; q < key_len; q++) {
                        graph[i + p][j + q] += key[p][q];
                    }
                }
                if (Answer_Check(graph, lock_len)) {
                    return true;
                }
                for (int p = 0; p < key_len; p++) {
                    for (int q = 0; q < key_len; q++) {
                        graph[i + p][j + q] -= key[p][q];
                    }
                }


            }
        }
    }
    answer = false;

    return answer;
}
bool Answer_Check(vector<vector<int>> gr, int lock_len) {
    int count = 0;
    for (int i = lock_len; i < lock_len * 2; i++) {
        for (int j = lock_len; j < lock_len * 2; j++) {
            if (gr[i][j] == 1) {
                count += 1;
            }
            else {
                return false;
            }
        }
    }
    if (count == lock_len * lock_len) {
        return true;
    }
    return false;
}

vector<vector<int>> Rotate(vector<vector<int>> vv, int  key_len) {
    vector<vector<int>> tmp(key_len);
    for (int i = 0; i < key_len; i++) {
        for (int j = 0; j < key_len; j++) {
            tmp[i].push_back(0);
        }
    }
    for (int i = 0; i < key_len; ++i)
    {
        for (int j = 0; j < key_len; ++j)
        {
            tmp[j][key_len - i - 1] = vv[i][j];
        }
    }
    return tmp;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> K(n);
    vector<vector<int>> L(m);
    cout << "KEY 입력" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int data;
            cin >> data;
            K[i].push_back(data);
        }
    }
    cout << "LOCK 입력" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int data;
            cin >> data;
            L[i].push_back(data);
        }
    }
    cout << "-------------" << endl;

    //K= Rotate(K, n);

    solution(K, L);



   

    return 0;
}