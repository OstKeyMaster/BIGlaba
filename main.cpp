#include <iostream>
using namespace std;

#include "ID_Stroka.h"
#include "Dec_Stroka.h"

int main() {
    ID_Stroka alb("Alabama");
    ID_Stroka cool("Cool");
    alb = alb + cool;
    alb.Show();
    cout << alb[3] << endl;
}
