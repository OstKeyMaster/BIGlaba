#include <iostream>
using namespace std;

#ifndef _STROKA_
#define _STROKA_
class Stroka {
protected:
    int len;
    char * pch;
public:
    Stroka(int = 0);  //Конструктор по ДЛИНЕ строки

    Stroka(char);  //Конструктор по символу

    Stroka(const char *);  //Конструктор по строке

    Stroka(const Stroka &);  //Конструктор копирования

    ~Stroka();

    int Len() {
        //cout << "Stroka::Len()" << endl;
        return len;
    }

    char * Str() const {
        //cout << "Stroka::Str()" << endl;
        return pch;
    }

    void Show();
};

#endif //_STROKA_
