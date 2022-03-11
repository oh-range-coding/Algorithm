#include <string>
#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;
bool compare(pair<float, int> a, pair<float, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first >= b.first;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> data;
    for (int i = 1; i <= N; i++) {

        int fail_cnt = 0;
        int contain_cnt = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (i <= stages[j]) {
                contain_cnt += 1;
            }
            if (i == stages[j]) {
                fail_cnt += 1;
            }
        }
        float value;
        if (contain_cnt == 0) {
            value = 0;
        }
        else
            value = (float)fail_cnt / contain_cnt;
        data.push_back({ value,i });

    }

    sort(data.begin(), data.end(), compare);
    for (int i = 0; i < N; i++) {
        answer.push_back(data[i].second);
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<int> data;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        data.push_back(d);
    }
    vector<int> result= solution(n, data);
    //for (int i = 0; i < result.size(); i++) {
    //    cout << result[i] << " ";
    //}
   
    


	return 0;
}