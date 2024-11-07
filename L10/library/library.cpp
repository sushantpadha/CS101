#include "library.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

Book::Book(const string &title, const string &author, const string &bookID)
    : m_title(title), m_author(author), m_bookID(bookID), isAvailable(true) {}

void Book::borrow() { isAvailable = false; }

void Book::returnBook() { isAvailable = true; }

bool Book::getStatus() { return isAvailable; }

////////////////////////////////////////////////////////////////////////////////

Library::Library() {}

void Library::addBook(const string &title, const string &author, const string &bookID) {
    Book book(title, author, bookID);

    books.push_back(book);
}

int Library::borrowBook(const string &bookID) {
    for (Book &book : books) {
        if (book.m_bookID == bookID) {
            if (!book.getStatus())
                return -1;
            book.borrow();
            return 1;
        }
    }
    return -1;
}

void Library::returnBook(const string &bookID) {
    for (Book &book : books) {
        if (book.m_bookID == bookID) {
            book.returnBook();
            return;
        }
    }
}

void Library::listBooks() {
    for (Book &book : books) {
        cout << book.m_title << '\n' << book.m_author << '\n' << book.m_bookID << '\n';
        cout << (book.getStatus() ? 'A' : 'N') << '\n';
    }
}