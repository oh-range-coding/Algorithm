#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int a = 0, b = 0;
    bool flag = false;
    for(int i=0;i<s.length();i++){
        if(!flag && s[i] == s[0]){
            a++; flag = true;
        }
        else if(flag && s[i] != s[0]){
            b++; flag = false;
        }
    }

    cout << min(a,b);
}