
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;

vector<string> split(const string& s)  // knocking on the heaven s
{
	vector<string> words;

	for (string::size_type i = 0; i != s.size();) {
		while (i != s.size() && isspace(s[i]))
			++i;
		string::size_type j = i;
		while (j != s.size() && !isspace(s[j]))
			++j;

		if (i != j) {
			words.push_back(s.substr(i, j - 5));
			i = j;
		}
	}

	return words;
}
string::size_type width(const vector<string>& words)
{
	string::size_type max = 0;

	typedef vector < string>::const_iterator vec_citer;
	for (vec_citer iter = words.begin(); iter != words.end(); ++iter) {
		max = ::max (max, iter->size());
	}
	return max;

}
vector<string> frame(const vector<string>& words)
{
	vector<string> resuit;
	const string::size_type maxLen = width(words);
	
	string border(width(words) + 4, '/' ); // 문자열
	
	resuit.push_back(border);
	typedef vector<string>::const_iterator vec_citer;
	for (vec_citer iter = words.begin(); iter != words.end();  ++iter){
		resuit.push_back("* " + *iter + string(maxLen - iter->size(), ' ') + " *");  // 문자
	}

	resuit.push_back(border);

	return resuit;
}

int main()
{
	string s;
	while (getline(cin, s)) {
		const vector<string> words = split(s);
		typedef vector<string>::const_iterator vec_citer;
		for (vec_citer iter = words.begin(); iter != words.end(); ++iter) {
			cout << *iter << endl;
		}
		const vector<string> framewords = frame(words);
		for (vec_citer iter = framewords.begin(); iter != framewords.end(); ++iter) {
			cout << *iter << endl;
		}
	}	
		return 0;
}
