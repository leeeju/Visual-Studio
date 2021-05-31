
#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;


int main()
{
	vector <string> words;

	string word; // 선언하기
	while (cin >> word) {
		words.push_back(word);
	}

	for (int i = 0; i < words.size(); i++)
		cout << words[i] << endl;

	string maxString = words[0];
	string minString = words[0];

	for (int i = 1; i < word.size(); i++) {
		if (maxString.size() < words[i].size()) {
			maxString = word[i];
		}
		if (minString.size() < words[i].size()) {
			minString = word[i];
		}
	
	}
	cout << "maxString : " << maxString << endl;
	cout << "minString : " << minString << endl;

	return 0;
}
