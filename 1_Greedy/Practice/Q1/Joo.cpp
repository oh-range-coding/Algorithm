#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 1000

int N, M, K;
int arr[MAX];

int main(){
    // input
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);
    int a = arr[N-1]; // 첫번째로 가장 큰 수
    int b = arr[N-2]; // 두번째로 가장 큰 수

    cout << (a * K + b) * (M / (K+1)) + (a * M % (K + 1));
}