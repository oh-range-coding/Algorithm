#include<iostream>
using namespace std;

#define MAX 10

int N, M, x;
int arr[MAX+1];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> x;
        arr[x]++;
    }

    int answer = N*(N-1)/2;
    for(int i=1;i<=M;i++){
        if(arr[i] > 1){
            answer -= arr[i] * (arr[i] - 1) / 2;
        } 
    }

    cout << answer;
}