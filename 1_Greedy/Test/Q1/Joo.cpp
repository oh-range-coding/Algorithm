#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100000

int N, tmp;
int arr[MAX+2];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        arr[tmp]++;
    }

    int answer = 0;
    for(int i=1;i<=N;i++){
        answer += arr[i] / i;
        arr[i+1] += arr[i] % i;
    }

    cout << answer;
}