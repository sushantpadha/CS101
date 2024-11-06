#include <string>
#include <vector>
using std::string;
using std::vector;

class Book {
public:
    string m_title, m_author, m_bookID;
    bool isAvailable;

    Book(const string &title, const string &author, const string &bookID);

    void borrow();

    void returnBook();

    bool getStatus();
};

class Library {
    vector<Book> books;

public:
    Library();

    void addBook(const string &title, const string &author, const string &bookID);

    int borrowBook(const string &bookID);

    void returnBook(const string &bookID);

    void listBooks();
};
