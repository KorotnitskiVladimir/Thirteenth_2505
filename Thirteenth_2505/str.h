#include <iostream>
using namespace std;

class String
{
private:
    char* str;
public:
    String()
    {
        str = new char[81];
    }
    String(const char* s)
    {
        str = new char[strlen(s)+1];
        strcpy_s(str, strlen(s)+1, s);
    }
    String(int n)
    {
        str = new char[n+1];
    }
    ~String()
    {
        delete [] str;
    }
    void setStr();
    char* getStr();
};

void String::setStr()
{
    cout << "enter string -> " << endl;
    char buff[255];
    gets_s(buff);
    if (strlen(buff)>0)
    {
        str = new char[strlen(buff)+1];
        strcpy_s(str, strlen(buff)+1, buff);
    }
    else
        cout << "not able to create string" << endl;
}
char* String::getStr()
{
    return str;
}

