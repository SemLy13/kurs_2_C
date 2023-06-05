#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class MyString {
public:
    char* str;
    
    MyString(char* str) {
        this->str = str;
    }

    int length(char* str) {
        return strlen(str);
    }

    MyString (char* a,char* b) {
        strcpy(a, b);
        str = a;
    }
    void print() {
        for (int i = 0; i < length(str); i++)
        {
            cout << str[i];
        }
    }
};

int main()
{
    MyString a ("Hello");
    a.print();
}

