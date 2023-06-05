#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

class MyString {
private:
    char* str;
    char* s2;
public:
    MyString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        s2 = new char[128];
        strcpy(s2, "arestdyfugihojkgdjhhkfkjj");
    }

    const char* c_str() const { return str; }

    int find(const char* word) const { //поиск
        char* pos = strstr(str, word);
        if (pos) {
            return pos - str;
        }
        else {
            return -1;
        }
    }

    void replace(const char* oldWord, const char* newWord) { //замена
        int oldWordLen = strlen(oldWord);
        int newWordLen = strlen(newWord);
        char* str2 = new char[strlen(str) /* - strlen(oldWord) + strlen(newWord)*/ + 1];
        strcpy(str2, str);

        for (char* pos = strstr(str2, oldWord); pos != nullptr;
            pos = strstr(pos + newWordLen, oldWord)) {
            memmove(pos + newWordLen, pos + oldWordLen, strlen(pos + oldWordLen) + 1);
            memcpy(pos, newWord, newWordLen);
        }
        strcpy(str, str2);
        cout << s2 << endl;
    }

    MyString ConCat(const MyString& other) const { //объединение строк
        char* newStr = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        return MyString(newStr);
    }
};

int main() {
    MyString myStr("Test again");
    cout << myStr.c_str() << endl << endl;

    const char* word = "test";
    int position = myStr.find(word);
    if (position != -1) {
        cout << "Found \"" << word << "\" at position " << position << endl << endl;
    }
    else {
        cout << "Did not find \"" << word << "\"" << endl << endl;
    }

    myStr.replace("Test", "Example Example Example");
    cout << myStr.c_str() << endl << endl;

    MyString str1("Hello, ");
    MyString str2("World!");
    MyString str3 = str1.ConCat(str2);
    cout << "Concatenated string: " << str3.c_str() << endl << endl;

    return 0;
}
