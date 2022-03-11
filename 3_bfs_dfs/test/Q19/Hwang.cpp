#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	string type = "0123";
	vector<int> data;
	string op_list="";
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		data.push_back(d);
	}
	//cin.ignore();
	for (int i = 0; i < 4; i++) {
		int amount;
		cin >> amount;
		if (amount >= 1) {
			for (int j = 0; j < amount; j++) {
				op_list += type[i];
			}
		}
	}
	sort(op_list.begin(), op_list.end());

    //а╤гу 
    int len = op_list.size();
    int len_2 = data.size()-1;

	int min_value = 1000000000;
	int max_value = -1000000000;
    do {
        string tmp="";
        for (int k = 0; k < len_2; k++) {
            tmp+=op_list[k];
        }

		int result=data[0];
		int start_value;
		int k = 0;
		for (int i = 1; i < data.size(); i++) 
		{
			switch (tmp[k++]) {
			case '0':
				result += data[i];
				break;
			case '1':
				result -= data[i];
				break;
			case '2':
				result *= data[i];
				break;
			case '3':
				if (data[i] < 0) {
					data[i] *= -1;
					result /= data[i];
					result *= -1;
				}
				else {
					result /= data[i];
				}
				break;
			}

		}
		if (min_value > result) {
			min_value = result;
		}
		if (max_value < result) {
			max_value = result;
		}



    } while (next_permutation(op_list.begin(), op_list.end()));
	cout << max_value << endl;
	cout << min_value << endl;
	
	return 0;
}