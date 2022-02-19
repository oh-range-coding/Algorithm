#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int answer = s[0] - '0';
    for(int i=1;i<s.length();i++){
        int x = s[i] - '0';
        if(answer <= 1 || x <= 1){
            answer += x;
        }
        else{
            answer *= x;
        }
    }

    cout << answer;
}