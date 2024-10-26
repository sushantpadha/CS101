#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "stringConcat.h"

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;
using std::string;
using std::vector;

int main()
{
    char input1[101], input2[101];
    cin.getline(input1, 101);
    cin.getline(input2, 101);

    String str1(input1);
    String str2(input2);
    String result = str1 + str2;

    result.display();

    return 0;
}
