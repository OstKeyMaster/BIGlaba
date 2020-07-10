#include <iostream>
using namespace std;
#include <windows.h>

#include "ID_Stroka.h"
#include "Dec_Stroka.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow) {

    Dec_Stroka abc("-1200");
    Dec_Stroka num("1200");
    cout << "num == abc : " << (num == abc) << endl;
    //MessageBox(nullptr, sum.Sign(), "The Truth", MB_OKCANCEL);

    return 0;
}
