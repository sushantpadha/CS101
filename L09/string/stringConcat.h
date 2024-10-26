class String {
    char ptr[202];

public:
    String(char* const other);

    String operator+(const String& other);

    void display();
};