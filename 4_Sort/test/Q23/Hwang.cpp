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
		cout << data[i].name<<'\n'; // <- �ð��ʰ��� �ֹ��̿��� endl��
	}
	// endl << 
	// �� �ʹ� ���� �ð��� ��ƸԾ ������ �������ϴ�.
	// endl�� ���۸� flush�ϴ� ������ ���ϱ� ������ 
	// �� ó�� ���� ����� �ؾ��ؼ� endl�� ���� ���ɶ��� 
	// endl����� �����ϰ� '\n'�� ����ؾ� �մϴ�.

	return 0;
}