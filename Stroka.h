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

Stroka::Stroka(int a): len(a), pch(new char[len+1]()) {
    if (a == 0) pch[0] = '\0';
    cout << "Stroka::Stroka(int a)" << endl;
}

Stroka::Stroka(char ch): len(1), pch(new char[len+1]()) {
    pch[0] = ch;
    pch[1] = '\0';
    cout << "Stroka::Stroka(char ch)" << endl;
}

Stroka::Stroka(const char * S): len(strlen(S)), pch(new char[len+1]()) {
    for (int i = 0; i < len; i++) {
        pch[i] = S[i];
    }
    cout << "Stroka::Stroka(const char * S)" << endl;
}

Stroka::Stroka(const Stroka &src_obj) : len(src_obj.len), pch(new char[len + 1]) {
    char * ptr = src_obj.pch;
    for (int i = 0; i <= len; i++) {
        *pch++ = *ptr++;
    }
    pch -= len + 1;
    cout << "Stroka::Stroka(const Stroka & src_obj)" << endl;
}

Stroka::~Stroka() {
    delete[] pch;
    cout << "Stroka::~Stroka()" << endl;
}



void Stroka::Show() {
    cout << "pch = " << pch << endl;
    cout << "len = " << len << endl;
    cout << "void Stroka::Show(void)" << endl;
}

#endif //_STROKA_
