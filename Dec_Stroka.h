#include "Stroka.h"
#include <cmath>
#include <iostream>
using namespace std;

#ifndef _DEC_STROKA_
#define _DEC_STROKA_

class Dec_Stroka: public Stroka {
public:
    explicit Dec_Stroka();  //Конструктор пустой

    explicit Dec_Stroka(const char *);  //Конструктор по строке

    Dec_Stroka(const Dec_Stroka &);  //Конструктор копирования

    virtual ~Dec_Stroka();  //Деструктор

    const char * (Sign());  //Информация о знаке (+ или -)

    Dec_Stroka & operator=(const Dec_Stroka &);  //Оператор присваивания

    explicit operator int() const;  //Преобразование в int

    friend Dec_Stroka operator+(const Dec_Stroka &, const Dec_Stroka &);  //Сумма чисел

    friend Dec_Stroka operator-(const Dec_Stroka &, const Dec_Stroka &);  //Разность чисел

    friend int operator==(const Dec_Stroka &, const Dec_Stroka &);  //Равны ли числа (да: 1, нет:0)
};

#endif //_DEC_STROKA_
