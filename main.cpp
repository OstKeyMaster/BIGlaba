#include <iostream>
using namespace std;

class Stroka {
protected:
    int len;
    char * pch;
public:
    Stroka(int = 0); // Stroka obj(25);

    Stroka(char); // Stroka obj('F');

    Stroka(const char *); // Stroka obj("ITMO");

    Stroka(const Stroka &); // Stroka obj(obj1);

    ~Stroka();

    int GetLen(void) const {return len;}

    char * GetStr(void) const {return pch;}

    void Show(void);
};

Stroka::Stroka(int a): len(a), pch(new char[len+1]) {
    if (a == 0) pch[0] = '\0';
    cout << "Stroka::Stroka(int a)" << endl;
}

Stroka::Stroka(char ch): len(1), pch(new char[len+1]) {
    pch[0] = ch;
    pch[1] = '\0';
    cout << "Stroka::Stroka(char ch)" << endl;
}

Stroka::Stroka(const char * S): len(strlen(S)), pch(new char[len+1]) {
    strcpy_s(pch, len + 1, S);
    cout << "Stroka::Stroka(const char * S)" << endl;
}

Stroka::Stroka(const Stroka &_object) : len(_object.len), pch(new char[len + 1]) {
    //strcpy_s(pch, len + 1, _object.pch);
    char * ptr = _object.pch;
    for (int i = 0; i <= len; i++) {
        *pch++ = *ptr++;
    }
    pch -= len + 1;
    cout << "Stroka::Stroka(const Stroka & _object)" << endl;
}

Stroka::~Stroka() {
    if (pch) delete[] pch;
    cout << "Stroka::~Stroka()" << endl;
}

void Stroka::Show(void) {
    cout << "pch = " << pch << endl;
    cout << "len = " << len << endl;
    cout << "void Stroka::Show(void)" << endl;
}

int main() {
    Stroka obj("ITMO");

    /*obj.Show();
    cout << obj.GetStr() << endl;
    cout << obj.GetLen() << endl;*/

    Stroka obj1 = obj;
    obj1.Show();
    return 0;
}

