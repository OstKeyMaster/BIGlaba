#include <iostream>
using namespace std;

#include "Stroka.h"

#ifndef _DEC_STROKA_
#define _DEC_STROKA_

class Dec_Stroka: public Stroka {
public:
    Dec_Stroka(int = 0);

    Dec_Stroka(const char *);

    Dec_Stroka(const Dec_Stroka &);

    ~Dec_Stroka();

    Dec_Stroka & operator=(const Dec_Stroka &);

    //friend Dec_Stroka operator+(const Dec_Stroka &, const Dec_Stroka &);

    //friend Dec_Stroka operator-(const Dec_Stroka &, const Dec_Stroka &);

    //friend Dec_Stroka operator==(const Dec_Stroka &, const Dec_Stroka &);
};

Dec_Stroka::Dec_Stroka(int val): Stroka(val) {
    cout << "Dec_Stroka::Dec_Stroka(int val)" << endl;
}

Dec_Stroka::~Dec_Stroka() {
    cout << "Dec_Stroka::Dec_Stroka()" << endl;
}

/*строка неачинается с цифры или +-, далее только цифры, иначе строка пустая*/
Dec_Stroka::Dec_Stroka(const char * str): Stroka(str) {
    if ((pch[0] >= '0' && pch[0] <= '9') || pch[0] == '+' || pch[0] == '-') {
        int i = 1;
        while(pch[i]) {
            if (pch[i] >= '0' && pch[i] <= '9') {}
            else {
                if (pch) delete[] pch;
                len = 0;
                pch = new char[len + 1];
                pch[0] = '\0';
                cout << "Dec_Stroka Bad Symbol!" << endl;
                return;
            }
            i++;
        }
    }
    else {
        if (pch) delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\0';
        cout << "Dec_Stroka Bad Symbol!" << endl;
    }
    cout << "Dec_Stroka::Dec_Stroka(const char * str)" << endl;
}

//конструктор копировния
Dec_Stroka::Dec_Stroka(const Dec_Stroka & from): Stroka(from) {
    cout << "Dec_Stroka::Dec_Stroka(const Dec_Stroka & from)" << endl;
}

//Оператор присваивания
Dec_Stroka & Dec_Stroka::operator=(const Dec_Stroka & DS) {
    if (&DS != this) {
        delete[] pch;
        len = strlen(DS.pch);
        pch = new char[len + 1];
        strcpy_s(pch, len + 1, DS.pch);
    }
    cout << "Dec_Stroka & Dec_Stroka::operator=(const Dec_Stroka & DS)" << endl;
    return * this;
}

#endif //_DEC_STROKA_
