#include <iostream>
#include <cstring>
#include "str.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Str s1 = "hello, world";
    Str s2(10, 'A');
    const char *str = "wonderful tonight";
    Str s3(str, str + strlen(str));
    Str s4;

    s1[0] = 'H';

    //cin >> s4;
    //cout << "s4 : " << s4 << endl;

    Str s5 = "hello";
    Str s6 = ", ";
    s5 += s6;
    s5 += "world";

    s6 = s5 + " ROS";

    // Str s7 = "hello, " + "world";       // ::operator+("hello", "world") ??

    cout << "s5 : " << s5 << endl;
    cout << "s6 : " << s6 << endl;

    const char *str1 = s6.c_str();
    cout << "str : " << str1 << endl;

    const char *str2 = s6.data();
    cout << "str2 : ";
    for (int i = 0; i < s6.size(); ++i)
        cout << str2[i];
    cout << endl;

    char *str3 = new char[s6.size() + 1];
    s6.copy(str3, s6.size());
    str3[s6.size()] = '\0';
    cout << str3 << endl;
    return 0;
}
