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
    //int count = 0;
    //while (*S++)
    strcpy_s(pch, len + 1, S);
    cout << "Stroka::Stroka(const char * S)" << endl;
}

Stroka::Stroka(const Stroka &src_obj) : len(src_obj.len), pch(new char[len + 1]) {
    //strcpy_s(pch, len + 1, src_obj.pch);
    char * ptr = src_obj.pch;
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

    friend ID_Stroka operator+(const ID_Stroka &, const ID_Stroka);//  concatenate

    friend ID_Stroka operator+(const ID_Stroka, const char *);

    friend ID_Stroka operator+(const char *, const ID_Stroka);
};
ID_Stroka::ID_Stroka(int a): Stroka(a) {
    cout << "ID_Stroka::ID_Stroka(int a):Stroka(a)" << endl;
}

ID_Stroka::ID_Stroka(char ch):Stroka(ch) {
    if (pch[0] >= 'A' && pch[0] <= 'z' && pch[0] == '_') {}
    else {
        if (pch) delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\0';
        cout << "Bad Symbol!" << endl;
    }
}

int main() {
    Stroka obj("PBKS_ITMO");

    /*obj.Show();
    cout << obj.GetStr() << endl;
    cout << obj.GetLen() << endl;*/

    Stroka obj1 = obj;
    obj.Show();
    obj1.Show();
    return 0;
}

