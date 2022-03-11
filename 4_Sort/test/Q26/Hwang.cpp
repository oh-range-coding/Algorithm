#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    priority_queue<int, vector<int>, greater<>> comp_cards;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        comp_cards.push(data);
    }
    int sum = 0;
    while (comp_cards.size() != 0) {

        /*for (int i = 0; i < comp_cards.size(); i++) {


           cout<<comp_cards[i]<<" ";
        }cout << endl;*/
        int cmp_a = comp_cards.top();
        comp_cards.pop();
        if (comp_cards.size() == 0) {
            //sum += cmp_a;
            break;
        }
        int cmp_b = comp_cards.top();
        comp_cards.pop();
        int value = cmp_a + cmp_b;
        sum += value;
        comp_cards.push(value);

    }
    cout << sum;


    return 0;
}