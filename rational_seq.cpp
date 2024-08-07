#include <iostream>
#include <unistd.h>
// #include <windows.h>

using namespace std;

/*
Generates all rational numbers in a sequential manner that can be bijected to the set of natural numbers
*/

int main()
{
    int i = 2;
    int j = 1;

    cout << 0 << endl;
    cout << "±" << 1 << endl;

    while (true)
    {
        while (j < i)
        {
            cout << "±" << j << "/" << i << " ";
            j++;
        }
        cout << endl;
        j = 1;
        i++;
        sleep(1);
    }
}