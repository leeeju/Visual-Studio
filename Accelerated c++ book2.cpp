
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	cout << "당신의 이름은 무었입니까?? : ";
	string name;
	cin >> name;

	cout << "내이름은  : " + name << endl;
	cout << "평가 점수는? : ";

	int midterm, finalterm;
	cin >> midterm >> finalterm;

	cout << " 당신의 공부 점수  ";
	std::vector<double> homework;

	double hw;
	while (cin >> hw) {
		homework.push_back(hw);
	}
	if (homework.size() == 0) {
		cout << " " << endl;
		return 1;
	}
	int mid;
	sort (homework.begin(), homework.end());

	if (homework.size() % 2 == 1)
		mid = homework[homework.size() / 2];
	else
		mid = (homework[homework.size() / 2] + homework[homework.size()] / 2 - 1);

	std::streamsize prec = cout.precision();
	cout << std::setprecision(3);
	cout << "오늘의 점수는~~ : " << 0.2 * midterm + 0.4 * finalterm + 0.4 * mid << endl;
	cout << std::setprecision(prec);

	return 0;
}
