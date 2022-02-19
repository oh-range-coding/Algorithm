#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 1000

int N, arr[MAX];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int answer = 0;
    for(int i=0;i<N;i++){
        if(answer+1 < arr[i]){
            break;
        }
        answer += arr[i];
    }

    answer += 1;
    cout << answer;
}