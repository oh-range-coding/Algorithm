#include<iostream>
using namespace std;

int main(){
    int N, K;
    int answer = 0;
    cin >> N >> K;

    while(N >= K){
        if(N%K){
            answer += N%K;
            N -= N%K;
        }
        else{
            answer += 1;
            N /= K;
        }
    }

    answer += N-1;
    cout << answer;
}