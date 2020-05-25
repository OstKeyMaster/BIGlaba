#include <iostream>
using namespace std;

#include "Stroka.h"
#include "ID_Stroka.h"
#include "Dec_Stroka.h"

int main() {
    Dec_Stroka qwe("-3459");
    Dec_Stroka err("123");
    err.Show();
    err = qwe;
    err.Show();
}
