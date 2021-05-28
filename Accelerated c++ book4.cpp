#include <iostream>
#include <string>  //스트링 클라스 <문자열연산>

int main()
{
    std::cout << "piease entre your first name : " << std::endl;
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";
    const std::string space(greeting.size(), ' ');         // 사이즈 = 문자열 생성
    const std::string secondLine = "* " + space + " *";
    const std::string firstLine(secondLine.size(), ' *');   // 사이즈 = 문자열 생성

    std::cout << firstLine << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << firstLine << std::endl;

    return 0;
}
