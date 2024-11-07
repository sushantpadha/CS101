#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "library.h"

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;
using std::string;
using std::vector;

int main()
{
    Library library;
    int operations;
    cin >> operations;
    cin.ignore(); // Clear the newline character from the buffer

    while (operations--)
    {
        int opType;
        cin >> opType;
        cin.ignore(); // Clear the newline character after reading opType

        if (opType == 1)
        { // Add book
            string title, author, bookID;
            getline(cin, title);
            getline(cin, author);
            getline(cin, bookID);
            library.addBook(title, author, bookID);
        }
        else if (opType == 2)
        { // Borrow book
            string bookID;
            getline(cin, bookID);
            cout << library.borrowBook(bookID) << endl;
        }
        else if (opType == 3)
        { // Return book
            string bookID;
            getline(cin, bookID);
            library.returnBook(bookID);
        }
        else if (opType == 4)
        { // List books
            library.listBooks();
        }
    }

    return 0;
}
