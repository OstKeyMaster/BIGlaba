#include <iostream>
using namespace std;

#include "ID_Stroka.h"
#include "Dec_Stroka.h"

static int N = 0;
static Stroka ** main_arr_ptr;
static int * main_arr_types; //TODO

void Initialize();
void Testing();
const char * Stroka_type(int);

int main() {
    N = 4;
    main_arr_ptr = new Stroka *[N];
    main_arr_ptr[0] = new Stroka("123hello");
    main_arr_ptr[1] = new ID_Stroka("hello_123");
    main_arr_ptr[2] = new Dec_Stroka("-12305");
    //main_arr_ptr[3] = nullptr;
    //Initialize();
    Testing();

    // Deleting main_arr_ptr
    /*for (int i = 0; i < N; i++) {
        if (main_arr_ptr[i] != nullptr)
            delete[] main_arr_ptr[i];  //TODO error??
    }
    delete[] main_arr_ptr;*/
    return 0;
}

void Initialize() {
    while(true) {
        if (N == 0) {
            cout << "1. Initializing (choose action number):\n"
                    "\t1) Number of elements\n"
                    "\t2) Initial values (Not available)\n"
                    "\t0) Back (go to Testing)\n"
                    "> ";
        } else if (N > 0) {
            cout << "1. Initializing (choose action number):\n"
                    "\t1) Number of elements (Not available)\n"
                    "\t2) Initial values\n"
                    "\t0) Back\n"
                    "> ";
        }
        int action;
        cin >> action;
        switch (action) {
            case 0:
                return;
            case 1:
                if (N == 0) {
                    cout << "Enter number of elements\n> ";
                    cin >> N;
                    if (N <= 0) {
                        cout << "The number must be positive" << endl;
                        N = 0;
                        continue;
                    }
                    main_arr_ptr = new Stroka *[N];
                    main_arr_types = new int[N]();
                    for (int i = 0; i < N; i++)
                        main_arr_ptr[i] = nullptr;
                    cout << "The number of elements is set as " << N << ".\n" << endl;
                } else if (N > 0) {
                    cout << "This part is not available already." << endl;
                }
                break;
            case 2:
                if (N == 0) {
                    cout << "This part is not available. Set the number of elements first." << endl;
                } else if (N > 0) {
                    int elmt, type;
                    while(true) {
                        cout << "List of elements:" << endl;
                        for (int i = 0; i < N; i++) {
                            if (main_arr_ptr[i] == nullptr) {
                                cout << "\t" << i + 1 << "." << endl;
                            }
                            else {
                                cout << "\t" << i + 1 << ". " << Stroka_type(main_arr_types[i]) <<
                                "\t" << main_arr_ptr[i]->Str() << endl;
                            }
                        }
                        cout << "\nChoose element number (Enter 0 to go back)\n>" << endl;
                        cin >> elmt;
                        if (elmt == 0) break;
                        if (elmt > N || elmt < 0) {
                            cout << "You chosen the number that is not supported. Try again.\n" << endl;
                            continue;
                        }
                        cout << "You have chosen " << elmt << endl;
                        elmt--;
                        cout << "\nChoose type number:\n"
                                "\t1. Str\n"
                                "\t2. ID Str\n"
                                "\t3. Dec Str\n>";
                        cin >> type;
                        if (type < 1 || type > 3) {
                            cout << "You chosen the number that is not supported. Try again.\n" << endl;
                            continue;
                        }
                        cout << "Enter value of chosen element\n>";
                        char value[128];
                        cin >> value;
                        switch (type) {
                            case 1:
                                if (main_arr_ptr[elmt] != nullptr) {
                                    delete[] main_arr_ptr[elmt];
                                    main_arr_ptr[elmt] = nullptr;
                                }
                                main_arr_ptr[elmt] = new Stroka(value);
                                main_arr_types[elmt] = type;
                                break;
                            case 2:
                                if (main_arr_ptr[elmt] != nullptr) {
                                    delete[] main_arr_ptr[elmt];
                                    main_arr_ptr[elmt] = nullptr;
                                }
                                main_arr_ptr[elmt] = new ID_Stroka(value);
                                main_arr_types[elmt] = type;
                                break;
                            case 3:
                                if (main_arr_ptr[elmt] != nullptr) {
                                    delete[] main_arr_ptr[elmt];
                                    main_arr_ptr[elmt] = nullptr;
                                }
                                main_arr_ptr[elmt] = new Dec_Stroka(value);
                                main_arr_types[elmt] = type;
                                break;
                            default:
                                cout << "You chosen the number that is not supported. Try again.\n" << endl;
                        }
                    }
                }
                break;
            default:
                cout << "You chosen the number that is not supported. Try again.\n" << endl;
        }
    }
}

void Testing() {
    cout << "2. Testing (choose element number):" << endl;
    for (int i = 0; i < N; i++) {
        if (main_arr_ptr[i] == nullptr) {
            cout << "\t" << i + 1 << "." << endl;
        }
        else {
            cout << "\t" << i + 1 << ". " << Stroka_type(main_arr_types[i]) << "\t" << main_arr_ptr[i]->Str() << endl;
        }
    }
    int element;
    cin >> element;
    cout << "You have chosen element " << element << endl;
    //TODO
}

const char *Stroka_type(int num) {
    switch (num) {
        case 1:
            return "    [Stroka]    ";
        case 2:
            return "    [ID_Stroka] ";
        case 3:
            return "    [Dec_Stroka]";
        default:
            return "    [none]      ";
    }
}