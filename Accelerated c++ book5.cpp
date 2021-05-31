
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


double median(vector<double> vec)   // & 초기화 값 35번행 으로 간다
{
	sort(vec.begin(), vec.end());    // 점수의 입력값을 받는다

	const int mid = vec.size() / 2;
		return (vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid -1]) / 2;

}
double grade(double minterm, double finalterm, double homework)
{
	return 0.2 * minterm + 0.4 * finalterm + 0.4 * homework; // 숙제의 중간값을 산출한다

}                                                           
double grade(double minterm, double finalterm, const vector<double>& homeworks) // const로 초기화 값을 받는다, 홈웍에 왜?? 초기화?
{
	if (homeworks.size() == 0)
		throw domain_error("점수를 다시 말하거라");
	
	return grade(minterm, finalterm, median(homeworks)); // 중간고사, 기말고사 점수를 입력한다
}

istream& read_hw(istream& in, vector<double>& homework)
{
	if (in ) {
		homework.clear();  // 기존에 있던 homework을 초기화 해서 비워준다
		double x;         // 숫자가 들어가면  x는 사용자가 입력하는 숫자
		while (cin >> x) {  // 반복문  사용자 값을 입력 받는다 cin = x
			homework.push_back(x); // 들어간다
		}
		in. clear();
	}
		return in;
}

int main() //출력부분
{
	cout << "이름이 뭔가 : ";
	string name;
	cin >> name;

	cout << "나의 이름은  : " + name << endl;

	cout << "중간고사, 기말고사 : ";
	double imdterm, finalterm;
	cin >> imdterm >> finalterm;

	vector<double> homework;
	read_hw(cin, homework);

	try {
		std::streamsize prec = cout.precision();
		cout << std::setprecision(3);
		cout << "점수는~~과연~ 두근두근 : " << grade(imdterm, finalterm, homework) << endl;
		cout << std::setprecision(prec);

	}
	catch (domain_error& a) {
		cerr << "너의 점수를 다시 알려줘" << endl;
		
		return 1;
	
	}
	return 0;
}
