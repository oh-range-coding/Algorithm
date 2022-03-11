#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Student{
public:
	//Student() { kor = 0, eng = 0, math = 0, name = ""; }
	int kor, eng, math;
	string name;
};
bool Compare(Student a, Student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			else {
				return a.math > b.math;
			}
		}
		else {
			return a.eng < b.eng;
		}
	}
	else
	{
		return a.kor > b.kor;
	}
}

int main() {

	int n;
	cin >> n;
	vector<Student> data;
	for (int i = 0; i < n; i++) {
		Student st;
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		st.name = name;
		st.kor = kor;
		st.eng = eng;
		st.math = math;
		
		data.push_back(st);
		

	}
	
	sort(data.begin(), data.end(),Compare);
	for (int i = 0; i < n; i++) {
		cout << data[i].name<<'\n'; // <- 시간초과의 주범이였음 endl이
	}
	// endl << 
	// 이 너무 많은 시간을 잡아먹어서 에러가 났었습니다.
	// endl는 버퍼를 flush하는 역할을 겸하기 때문에 
	// 위 처럼 많은 출력을 해야해서 endl이 많이 사용될때는 
	// endl사용을 지양하고 '\n'을 사용해야 합니다.

	return 0;
}