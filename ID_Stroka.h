#include <iostream>
using namespace std;

#ifndef _ID_STROKA_
#define _ID_STROKA_
#include "Stroka.h"

class ID_Stroka: public Stroka {
public:
    ID_Stroka(int = 0);

    ID_Stroka(char);

    ID_Stroka(const char *);

    ID_Stroka(const ID_Stroka &);

    ~ID_Stroka();

    ID_Stroka &operator=(const ID_Stroka &);  //copy

    char &operator[](int);  //  add symbol by index

    ID_Stroka operator~();  //  reverse

    friend ID_Stroka operator+(const ID_Stroka &, const ID_Stroka &);//  concatenate

    // friend ID_Stroka operator+(const ID_Stroka, const char *);

    // friend ID_Stroka operator+(const char *, const ID_Stroka);
};
ID_Stroka::ID_Stroka(int a): Stroka(a) {
    cout << "ID_Stroka::ID_Stroka(int a):Stroka(a)" << endl;
}

ID_Stroka::ID_Stroka(char ch):Stroka(ch) {
    if ((pch[0] >= 'A' && pch[0] <= 'Z') || (pch[0] >= 'a' && pch[0] <= 'z') || pch[0] == '_') {
        cout << "ID_Stroka::ID_Stroka(char ch)" << endl;
    }
    else {
        if (pch) delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\0';
        cout << "Bad Symbol!" << endl;
    }
}

ID_Stroka::ID_Stroka(const char * Str):Stroka(Str) {
    if ((pch[0] >= 'A' && pch[0] <= 'Z') || (pch[0] >= 'a' && pch[0] <= 'z') || pch[0] == '_') {
        for (int i = 1; i < len; i++) {
            if (pch[i] == ' ') {
                if (pch) delete[] pch;
                len = 0;
                pch = new char[len + 1];
                pch[0] = '\0';
                cout << "Bad Symbol!" << endl;
                break;
            }
        }
    }
    else {
        if (pch) delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\0';
        cout << "Bad Symbol!" << endl;
    }

}

ID_Stroka::ID_Stroka(const ID_Stroka & from):Stroka(from) {
    cout << "ID_Stroka::ID_Stroka(const ID_Stroka & from)" << endl;
}

ID_Stroka::~ID_Stroka() {
    if (pch) delete[] pch;
    cout << "ID_Stroka::~ID_Stroka()" << endl;
}

ID_Stroka ID_Stroka::operator~() {
    int i, j;
    char tmp;
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        tmp = pch[i];
        pch[i] = pch[j];
        pch[j] = tmp;
    }
    cout << "ID_Stroka ID_Stroka::operator~()" << endl;
    return *this;
}

ID_Stroka & ID_Stroka::operator=(const ID_Stroka &S) {
    if (&S != this) {
        delete[] pch;
        len = strlen(S.pch);
        pch = new char[len + 1];
        //strcpy
        strcpy_s(pch, len + 1, S.pch);
    }
    cout << "ID_Stroka & ID_Stroka::operator=(const ID_Stroka & S)" << endl;
    return *this;
}

char &ID_Stroka::operator[](int Index) {
    if (Index >= 0 && Index < len) {
        cout << "char &ID_Stroka:: operator[](int Index)" << endl;
        return pch[Index];
    }
    return pch[0];
}

ID_Stroka operator+(const ID_Stroka &pobj1, const ID_Stroka &pobj2) {
    ID_Stroka tmp(pobj1.GetLen() + pobj2.GetLen());
    strcpy_s(tmp.pch, tmp.len + 1, pobj1.GetStr());
    strcat_s(tmp.pch, tmp.len + 1, pobj2.GetStr());
    cout << "ID_Stroka operator+(const ID_Stroka &pobj1, const ID_Stroka &pobj2)" << endl;
    return tmp;
}


#endif //_ID_STROKA_
