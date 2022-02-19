#include<iostream>
using namespace std;

#define MAX 10000

int main(){
    int N, M, tmp;
    int answer = 0;

    cin >> N >> M;
    for(int i=0;i<N;i++){
        int line_min = MAX;
        for(int j=0;j<M;j++){
            cin >> tmp;
            line_min = line_min < tmp ? line_min : tmp;
        }
        answer = answer > line_min ? answer : line_min;
    }

    cout << answer;
}