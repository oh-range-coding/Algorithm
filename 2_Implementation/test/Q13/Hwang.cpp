#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


using namespace std;

// 0 : ºóÄ­
// 1 : Áý
// 2 : Ä¡Å²Áý

int main() {

    int n, m;

    int graph[51][51] = { 0 };
    vector<pair<int, int>> chicken_pos;
    vector<pair<int, int>> house_pos;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int data;
            cin >> data;
            graph[i][j] = data;
            if (data == 2) {
                chicken_pos.push_back(make_pair(i, j));
            }
            else if (data == 1) {
                house_pos.push_back(make_pair(i, j));
            }
        }
    }
    //Á¶ÇÕ 

    int len = chicken_pos.size();

    vector<bool> v(len - m, false);
    v.insert(v.end(), m, true);
    int min_value = 1000000;
    do {
        vector<pair<int, int>> tmp;
        for (int k = 0; k < len; k++) {
            if (v[k]) tmp.push_back(chicken_pos[k]);
        }

        int sum = 0;
        for (int a = 0; a < house_pos.size(); a++) {
            int chick_dist = 1000000;
            for (int b = 0; b < tmp.size(); b++) {
                int tmp_ = abs(tmp[b].first - house_pos[a].first) + abs(tmp[b].second - house_pos[a].second);

                if (chick_dist > tmp_) {
                    chick_dist = tmp_;
                }
            }
            sum += chick_dist;
        }
        if (min_value > sum) {
            min_value = sum;
        }


    } while (next_permutation(v.begin(), v.end()));

    cout << min_value;
    //




    return 0;
}