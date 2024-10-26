#include "stringConcat.h"

#include <iostream>
using std::cout;

String::String(char* const other) {
    char* tmp = ptr;

    for (char* p = other; (*p) != 0; tmp++, p++) *tmp = *p;

    *tmp = 0;
}

String String::operator+(const String& other) {
    // create new string to return
    // it will use the default copy constructor
    String answer = (*this);

    char* tmp = answer.ptr;
    while ((*tmp) != 0) tmp++;

    // bloody test cases want me to add a space in between?
    *tmp = ' ';
    tmp++;

    for (const char* p = other.ptr; (*p) != 0; tmp++, p++) *tmp = *p;

    *tmp = 0;

    return answer;
}

void String::display() {
    for (char* tmp = ptr; (*tmp) != 0; tmp++) {
        cout << (*tmp);
    }
}