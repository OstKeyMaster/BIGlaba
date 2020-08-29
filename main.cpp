#include <iostream>
using namespace std;

#include "ID_Stroka.h"
#include "Dec_Stroka.h"

static int N = 0;
Stroka ** main_arr_ptr;

void Initialize();

int main() {
    Initialize();
    /*
    cout << "Enter number of variables: " << endl;
    cin >> N;
    Stroka ** main_arr_ptr = new Stroka *[N];
    for (int i = 0; i < N; i++) {
        cout << i+1 << ": ? (1: ID / 2: Dec)" << endl;
        char resp1;
        cin >> resp1;
        cout << "Enter value of " << ((resp1 == '1') ? "ID_Stroka" : "Dec_Stroka") << endl;
        char value[16];
        cin >> value;
        if (resp1 == '1') {
            main_arr_ptr[i] = new ID_Stroka(value);
        } else {
            main_arr_ptr[i] = new Dec_Stroka(value);
        }
    }

    // Showing values
    for (int i = 0; i < N; i++) {
        main_arr_ptr[i] -> Show();
    }

    // Deleting main_arr_ptr
    for (int i = 0; i < N; i++)
        delete[] main_arr_ptr[i];
    delete[] main_arr_ptr;*/
    return 0;
}

void Initialize() {
    while(1) {
        if (N == 0) {
            cout << "1. Initializing (choose action number):\n"
                    "\t1) Number of elements\n"
                    "\t2) Initial values (Not available)\n"
                    "\t0) Back\n"
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
                    while(1) {
                        cout << "List of elements:" << endl;
                        for (int i = 0; i < N; i++) {
                            if (main_arr_ptr[i] == nullptr)
                                cout << "\t" << i + 1 << "." << endl;
                            else
                                cout << "\t" << i + 1 << ". " << main_arr_ptr[i]->Str() << endl;
                        }
                        cout << "\nChoose element number (Enter 0 to go back)\n>" << endl;
                        int elmt, type;
                        cin >> elmt;
                        if (elmt == 0) break;
                        if (elmt > N) {
                            cout << "You chosen the number that is not supported. Try again.\n" << endl;
                            continue;
                        }
                        elmt--;
                        cout << "You have chosen " << elmt << endl;
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
                                main_arr_ptr[elmt] = new Stroka(value);
                                break;
                            case 2:
                                main_arr_ptr[elmt] = new ID_Stroka(value);
                                break;
                            case 3:
                                main_arr_ptr[elmt] = new Dec_Stroka(value);
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
