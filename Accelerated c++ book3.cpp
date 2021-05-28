
#include <iostream>
#include <string> 

int main()
{
	std::cout << "이름이 뭔가요 ? : ";

	std::string name;
	std::cin >> name;

	std::cout << "안녕?" << name << " ! " << std::endl;

	return 0;
} 
