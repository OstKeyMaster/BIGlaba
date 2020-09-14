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

    ~ID_Stroka();

    ID_Stroka upperCase();

    ID_Stroka &operator=(const ID_Stroka &);  //Оператор присваивания (ссылки)

    char &operator[](int);  //Опреатор возвращает символ по индексу

    ID_Stroka operator~();  //Оператор разворота строки

    friend ID_Stroka operator+(const ID_Stroka &, const ID_Stroka &);  //Конкатенация строк

    friend ID_Stroka operator+(const ID_Stroka &, const char *);

    friend ID_Stroka operator+(const char *, const ID_Stroka &);
};




#endif //_ID_STROKA_
