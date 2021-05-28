
#include <iostream>
#include <string>

using std::cin;
using std::cout;   // 이 4가지는 밑에서 std를 생략 할 수 있게 만들어 주는 '선언'이다
using std::endl;
using std::string;

int main()
{

	cout << " piease entre your first name   ";
	string name; // 스타일은 저장 한다
	cin >> name; // cin 입력값이다 scanf  같은 사용자의 입력
				 // 반대로 cout는 출력 값이다 printf 같은 것

	const string greeting = "hello " + name;
	const int pad = 2;                                     // 전부 std 가 생략 된것을 볼 수 있다
	const int pad2 = 3;
	const string::size_type rows = 2 * pad + 2;                    // 기본 출력 값 설정 (상, 하)
	const string::size_type cols = greeting.size() + 2 * pad2 + 2;  // 기본 출력값 설정 (좌, 우)


	cout << endl;
	for (int r = 0; r != rows; ++r) { // 반복문 테두리 크기 생성
		string::size_type c = 0;         // c 의 정의

		while (c != cols) {   // 반복문
			if(r == pad + 1 && c == pad +1 )   {  // ~~ 하는 동안
				cout << greeting;
				c += greeting.size();

		    }else {

				if (r ==  - 0 || r == rows - 1 || c == 0|| c == cols - 1)  // 시용자 임의 설정 가능
				//   상                하         좌             우           
					//  '*' 이 표시되는 부분 ↑ 테두리 크기 조절
				
					cout << "★";  // 츨력한다 * 을
				else
					cout << " ";  // 아닌곳은 공백
				c++;
			}
	}
	cout << endl;

} //

	return 0;
}//
