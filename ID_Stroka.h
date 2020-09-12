#include <iostream>
using namespace std;

#ifndef _ID_STROKA_
#define _ID_STROKA_
#include "Stroka.h"

class ID_Stroka: public Stroka {
public:
    ID_Stroka(int = 0);  //Конструктор по длине строки (пустой)

    ID_Stroka(char);  //Конструктор по символу

    ID_Stroka(const char *);  //Конструктор по строке

    ID_Stroka(const ID_Stroka &);  //Конструктор копирования

    virtual ~ID_Stroka();

    ID_Stroka upperCase();

    ID_Stroka &operator=(const ID_Stroka &);  //Оператор присваивания (ссылки)

    char &operator[](int);  //Опреатор возвращает символ по индексу

    ID_Stroka operator~();  //Оператор разворота строки

    friend ID_Stroka operator+(const ID_Stroka &, const ID_Stroka &);  //Конкатенация строк

    friend ID_Stroka operator+(const ID_Stroka &, const char *);

    friend ID_Stroka operator+(const char *, const ID_Stroka &);
};

ID_Stroka::ID_Stroka(int a): Stroka(a) {
    cout << "ID_Stroka::ID_Stroka(int a):Stroka(a)" << endl;
}

ID_Stroka::ID_Stroka(char ch):Stroka(ch) {
    if ((pch[0] >= 'A' && pch[0] <= 'Z')
    || (pch[0] >= 'a' && pch[0] <= 'z')
    || pch[0] == '_') {
        cout << "ID_Stroka::ID_Stroka(char ch)" << endl;
    }
    else {
        delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\0';
        cout << "Bad Symbol!" << endl;
    }
}

ID_Stroka::ID_Stroka(const char * Str):Stroka(Str) {
    if ((pch[0] >= 'A' && pch[0] <= 'Z')
    || (pch[0] >= 'a' && pch[0] <= 'z')
    || pch[0] == '_') {
        for (int i = 1; i < len; i++) {
            if (pch[i] == ' ') {
                delete[] pch;
                len = 0;
                pch = new char[len + 1];
                pch[0] = '\0';
                cout << "\t__Bad Symbol!__" << endl;
                break;
            }
        }
    }
    else {
        delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\0';
        cout << "\t__Bad Symbol!__" << endl;
    }

}

ID_Stroka::ID_Stroka(const ID_Stroka & from):Stroka(from) {
    cout << "ID_Stroka::ID_Stroka(const ID_Stroka & from)" << endl;
}

ID_Stroka::~ID_Stroka() {
    cout << "ID_Stroka::~ID_Stroka()" << endl;
}

ID_Stroka ID_Stroka::upperCase() {
    for (int i = 0; i < len; i++) {
        if(pch[i] >= 'a' && pch[i] <= 'z')
            pch[i] -= 32;
    }
    return *this;
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
        pch = new char[len + 1]();
        for (int i = 0; i <= len; i++)
            pch[i] = S.pch[i];
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
    ID_Stroka tmp(pobj1.len + pobj2.len);
    for (int i = 0; i < pobj1.len; i++)
        tmp.pch[i] = pobj1.pch[i];
    for (int i = 0; i <= pobj2.len; i++)
        tmp.pch[pobj1.len + i] = pobj2.pch[i];

    cout << "ID_Stroka operator+(const ID_Stroka &, const ID_Stroka &)" << endl;
    return tmp;
}

ID_Stroka operator+(const char * str1, const ID_Stroka &pobj2) {
    ID_Stroka str0(str1);
    ID_Stroka tmp(str0 + pobj2);

    cout << "ID_Stroka operator+(const char *, const ID_Stroka &)" << endl;
    return tmp;
}

ID_Stroka operator+(const ID_Stroka &pobj1, const char * str2) {
    ID_Stroka tmp(pobj1.len + (int)strlen(str2));
    for (int i = 0; i < strlen(str2); i++) {
        if ((str2[i] >= 'A' && str2[i] <= 'Z') || (str2[i] >= 'a' && str2[i] <= 'z')
            || str2[i] == '_' || (str2[i] >= '0' && str2[i] <= '9')) {

            for (int j = 0; j < pobj1.len; j++)
                tmp.pch[j] = pobj1.pch[j];
            for (int j = 0; j <= (int)strlen(str2); j++)
                tmp.pch[pobj1.len + j] = str2[j];
        } else {
            delete[] str2;
            cout << "\t__Bad Symbol!__" << endl;
            return pobj1;
        }
    }
    cout << "ID_Stroka operator+(const ID_Stroka &, const char *)" << endl;
    return tmp;
}




#endif //_ID_STROKA_
