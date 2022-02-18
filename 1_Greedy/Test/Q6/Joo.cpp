#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<int> tmp = food_times;
    sort(tmp.begin(), tmp.end());
    
    int idx;
    long long cnt; 
    for(idx=0;idx<tmp.size();idx++){
        if(idx == 0){
            cnt = (long long)tmp[idx] * tmp.size();
        }
        else{
            cnt = (long long)(tmp[idx] - tmp[idx-1]) * (tmp.size() - idx);
        }
        
        if(cnt > k){
            break;
        }
        else{
            k -= cnt;
        }
    }
    
    if(idx == tmp.size()) return -1;
    
    vector<int> remain_food;
    for(int i=0;i<food_times.size();i++){
        if(food_times[i] >= tmp[idx]){
            remain_food.push_back(i+1);
        }
    }
    
    k %= remain_food.size();
    return remain_food[k];
}