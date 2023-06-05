#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Stud
{
public:
    char* name;
    int year;
    float mark;
    Stud()
    {
        name = NULL;
        year = 0;
        mark = 0.0;
    }
    Stud(char* n) : Stud()
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }
    bool load(ifstream& fileInput)
    {
        char name[40];
        fileInput >> name;
        if (fileInput.eof())
            return 0;
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
        fileInput >> year >> mark;
        return 1;
    }
    int compare(Stud* k1)
    {
        return strcmp(name, k1->name);
    }
    void show()
    {
        cout << name << " " << year << " " << mark << endl;
    }
};

class MyInt
{
public:
    int i;
    MyInt()
    {
        i = 0;
    }
    MyInt(int n)
    {
        i = n;
    }
    bool load(ifstream& fileInput)
    {
        int n = -7777;
        fileInput >> n;
        if (fileInput.eof() && n == -7777)
            return 0;
        i = n;
        return 1;
    }
    int compare(MyInt* k1)
    {
        return (i - k1->i);
    }
    void show()
    {
        cout << i << " ";
    }
};

template <class T> class Collection
{
public:
    void** arr;
    int limit, delta, count;

    Collection() : limit(0), delta(0), count(0) {
        arr = NULL;
