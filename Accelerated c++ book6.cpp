
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <ios>
#include <iostream>
#include <iomanip>

using std::istream;
using std::vector;
using std::sort;
using std::domain_error;
using std::cin;
using std::cout;            // 미리 선언을 다 함으로 코드의 길이를 줄일 수 있다
using std::endl;
using std::cerr;
using std::string;
using std::setprecision;
using std::max;


struct Strdent_indo {
	string name;
	double minterm;   // 선언한다
	double finalterm;
	vector<double> homework;

};
double median(vector<double> vec)   // & 초기화 값 35번행 으로 간다
{
	sort(vec.begin(), vec.end());    // 숙제의 입력값을 받는다

	const int mid = vec.size() / 2;
	return (vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid - 1]) / 2;

}
double grade(double minterm, double finalterm, double homework)
{
	return 0.2 * minterm + 0.4 * finalterm + 0.4 * homework; // 숙제의 중간값을 산출한다

}
double grade(double minterm, double finalterm, const vector<double>& homeworks) // const로 초기화 값을 받는다, 홈웍에
{

	if (homeworks.size() == 0)
		throw domain_error("점수를 다시 말하거라");

	return grade(minterm, finalterm, median(homeworks)); // 중간고사 기말고사 점수를 입력한다
} // grade 3번째 인자 타입인 홈웍을 호출

double grade(const Strdent_indo& s)
{
	return grade(s.minterm, s.finalterm, s.homework);
}


istream& read_hw(istream& in, vector<double>& homework)
{
	if (in) { //이건 굳이 없어도 된다
		homework.clear();  // 기존에 있던 homework을 초기화 해서 비워준다
		double x;          // 숫자가 들어가면
		while (cin >> x) {  // 반복문 
			homework.push_back(x); // 들어간다
		}
		in.clear();
	}
	return in;
}

istream read(istream& in, Strdent_indo& s)
{
	in >> s.name >> s.minterm >> s.finalterm;
	read_hw(in, s.homework);
	
	return in;
}

bool compare(const Strdent_indo& s1, const Strdent_indo& s2)
{
	return s1.name > s2.name; // 이름을 2개만 비교한다
}

int main()
{
	vector<Strdent_indo> students;

	//int maxLen = 0;
	string::size_type maxLen = 0;
	Strdent_indo record;
	while (read(cin, record)) {
		students.push_back(record);
		maxLen = max(maxLen, record.name.size());
	}

	sort(students.begin(), students.end(), compare);

//	for (int i = 0; i < students.size(); i++) {
	for (vector<Strdent_indo>::size_type i = 0; i != students.size(); i++) {
		cout << students[i].name << string(maxLen - students[i].name.size() + 1, ' ');

		try {
		std::streamsize prec = cout.precision();
		cout << std::setprecision(3);
		cout << grade(students[i]) << endl;       // 출력문
		cout << std::setprecision(prec);

	}
		catch (domain_error& a) {     // 지정한 크기가 넘어가면 이걸 출력
			cerr << a.what() << endl;

			return 1;
		}
	
	}


	return 0;
}
