#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

//30Ка..;

int solution(string s) {
    int answer = 1000000;
    if (s.length() == 1) {
        return 1;
    }
    for (int i = 1; i < int(s.length()/2)+1; i++) {

        string tmp = "";
        string compare_word="";
        int count = 1;
        int last_idx=0;
        for (int j = 0; j < s.length()-i+1; j+=i) {
            if (s.substr(j, i) == compare_word) {
                count += 1;
                
            }
            else {
                if (count == 1) {
                    tmp += compare_word;
                }
                else if (count >= 2) {
                    string t = to_string(count) + compare_word;
                    tmp += t;
                    
                    
                }
                count = 1;
                compare_word = s.substr(j, i);
            }
            last_idx = j+i;
        }
        if (count == 1) {
            string t = compare_word;
            tmp += t;
        }
        else if (count >= 2) {
            string t = to_string(count) + compare_word;
            tmp += t;
        }
        if (last_idx < s.length()) {
            for (int a = last_idx; a < s.length(); a++) {
                tmp += s[a];
            }
        }
        if (answer > tmp.size()) {
            answer = tmp.size();
        }
    }
    return answer;
}

int main() {
    cout<< solution("ababcdcdababcdcd");
    string s = "aabbccc";

	return 0;
}