
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s0;
	string s1 = "hello, worid ";
	string s2 = s1;
	string s3(10, '*');
	string s4(10, 65);
	string s5(s1.begin(), s1.end());
	string s6(s1, 7, 5);

	const char* str = s1. c_str();
	cout << "str : " << str << endl;


	for (string::size_type i = 0; i !=  s1.size(); i++)
		cout << s1[i];
	cout << endl;

	for (string::const_iterator iter = s1.cbegin(); iter != s1.cend(); ++iter)
		cout << *iter;
	cout << endl;

	cout << "s1, sunbstr : " << s1.substr(7, 5);

	return 0;
}
