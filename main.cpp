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
    cout << "Welcome!" << endl;
    while(true) {
        if (N == 0) {
            cout << "\nMain menu:\n"
                    "\t0) Quit\n"
                    "\t1) Initializing\n"
                    "\t2) Testing (Not available)\n>";
        } else if (N > 0) {
            cout << "\nMain menu:\n"
                    "\t0) Quit\n"
                    "\t1) Initializing\n"
                    "\t2) Testing\n>";
        }
        int a;
        cin >> a;
        switch(a) {
            case 0:
                return 0;
            case 1:
                Initialize();
                break;
            case 2:
                if (N == 0) {
                    cout << "This part is not available. Go to Initializing first." << endl;
                } else if (N > 0) {
                    Testing();
                }
                break;
            default:
                cout << "You chosen the number that is not supported. Try again.\n" << endl;
        }
    }
}

void Initialize() {
    while(true) {
        if (N == 0) {
            cout << "\n1. Initializing (choose action number):\n"
                    "\t1) Number of elements\n"
                    "\t2) Initial values (Not available)\n"
                    "\t0) Back (go to Testing)\n"
                    "> ";
        } else if (N > 0) {
            cout << "\n1. Initializing (choose action number):\n"
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
                        cout << "\nChoose element number (Enter 0 to go back)\n>";
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
    while(true) {
        cout << "\n2. Testing (choose element number):" << endl;
        cout << "\t0.\tBack\n";
        for (int i = 0; i < N; i++) {
            if (main_arr_ptr[i] == nullptr) {
                cout << "\t" << i + 1 << "." << endl;
            } else {
                cout << "\t" << i + 1 << ". " << Stroka_type(main_arr_types[i]) << "\t" << main_arr_ptr[i]->Str()
                     << endl;
            }
        }
        cout << ">";
        int element;
        cin >> element;
        if (element == 0)
            return;
        if (element > N || element < 1) {
            cout << "You chosen the number that is not supported. Try again.\n" << endl;
            continue;
        }
        cout << "You have chosen element " << element << endl;
        element--;
        int choice;
        switch (main_arr_types[element]) {
            case 1: {
                cout << "Choose method number (0 for go back):\n"
                        "\t1) Str\n"
                        "\t2) Len\n"
                        "\t3) Show\n"
                        ">";
                cin >> choice;
                switch (choice) {
                    case 0:
                        break;
                    case 1:
                        cout << main_arr_ptr[element]->Str() << endl;
                        break;
                    case 2:
                        cout << main_arr_ptr[element]->Len() << endl;
                        break;
                    case 3:
                        main_arr_ptr[element]->Show();
                    default:
                        cout << "You chosen the number that is not supported. Try again.\n" << endl;
                }
                break;
            }
            case 2: {
                cout << "Choose method number:\n"
                        "\t1) Str\n"
                        "\t2) Len\n"
                        "\t3) Show\n"
                        "\t4) upperCase\n"
                        "\t5) = (assign)\n"
                        "\t6) [] (get symbol by index)\n"
                        "\t7) ~ (reverse)\n"
                        "\t8) + (concatenate)\n"
                        ">";
                cin >> choice;
                switch (choice) {
                    case 0:
                        break;
                    case 1:
                        cout << main_arr_ptr[element]->Str() << endl;
                        break;
                    case 2:
                        cout << main_arr_ptr[element]->Len() << endl;
                        break;
                    case 3:
                        main_arr_ptr[element]->Show();
                        break;
                    case 4:
                        main_arr_ptr[element] = new ID_Stroka(((ID_Stroka *) main_arr_ptr[element])->upperCase());
                        break;
                    case 5: {
                        int count = 0;
                        for (int i = 0; i < N; i++)
                            if (main_arr_types[i] == main_arr_types[element])
                                count++;
                        if (count > 1) {
                            cout << "Choose value to assign:" << endl;
                            for (int i = 0; i < N; i++)
                                if (main_arr_types[i] == main_arr_types[element] && i != element) {
                                    cout << "\t" << i + 1 << ". " << Stroka_type(main_arr_types[i]) <<
                                         "\t" << main_arr_ptr[i]->Str() << endl;
                                }
                            cout << ">";
                            cin >> choice;
                            *((ID_Stroka *) main_arr_ptr[element]) = *((ID_Stroka *) main_arr_ptr[choice - 1]);
                        } else {
                            cout << "There is no value to assign." << endl;
                        }
                        break;
                    }
                    case 6:
                        cout << "There is " << main_arr_ptr[element]->Len() <<
                             " symbols. Enter number of symbol (choose from 1 to " <<
                             main_arr_ptr[element]->Len() << "):\n>";
                        cin >> choice;
                        if (choice >= 1 && choice <= main_arr_ptr[element]->Len())
                            cout << (*((ID_Stroka *) main_arr_ptr[element]))[choice - 1] << endl;
                        break;
                    case 7:
                        ~*((ID_Stroka *) main_arr_ptr[element]);
                        break;
                    case 8: {
                        int count = 0;
                        for (int i = 0; i < N; i++)
                            if (main_arr_types[i] == main_arr_types[element])
                                count++;
                        if (count > 1) {
                            cout << "Choose value to concatenate:" << endl;
                            for (int i = 0; i < N; i++)
                                if (main_arr_types[i] == main_arr_types[element] && i != element) {
                                    cout << "\t" << i + 1 << ". " << Stroka_type(main_arr_types[i]) <<
                                         "\t" << main_arr_ptr[i]->Str() << endl;
                                }
                            cout << ">";
                            cin >> choice;
                            *((ID_Stroka *) main_arr_ptr[element]) = *((ID_Stroka *) main_arr_ptr[element]) +
                                                                     *((ID_Stroka *) main_arr_ptr[choice - 1]);
                        } else {
                            cout << "There is no value to concatenate." << endl;
                        }
                        break;
                    }
                    default:
                        cout << "You chosen the number that is not supported. Try again.\n" << endl;
                }
                break;
            }
            case 3: {
                cout << "Choose method number:\n"
                        "\t1) Str\n"
                        "\t2) Len\n"
                        "\t3) Show\n"
                        "\t4) Sign\n"
                        "\t5) = (assign)\n"
                        "\t6) + (add)\n"
                        "\t7) - (subtract)\n"
                        "\t8) == (is equal)\n"
                        ">";
                cin >> choice;
                switch (choice) {
                    case 0:
                        break;
                    case 1:
                        cout << main_arr_ptr[element]->Str() << endl;
                        break;
                    case 2:
                        cout << main_arr_ptr[element]->Len() << endl;
                        break;
                    case 3:
                        main_arr_ptr[element]->Show();
                        break;
                    case 4:
                        cout << ((Dec_Stroka *) main_arr_ptr[element])->Sign() << endl;
                        break;
                    case 5: {
                        int count = 0;
                        for (int i = 0; i < N; i++)
                            if (main_arr_types[i] == main_arr_types[element])
                                count++;
                        if (count > 1) {
                            cout << "Choose value to assign:" << endl;
                            for (int i = 0; i < N; i++)
                                if (main_arr_types[i] == main_arr_types[element] && i != element) {
                                    cout << "\t" << i + 1 << ". " << Stroka_type(main_arr_types[i]) <<
                                         "\t" << main_arr_ptr[i]->Str() << endl;
                                }
                            cout << ">";
                            cin >> choice;
                            *((Dec_Stroka *) main_arr_ptr[element]) = *((Dec_Stroka *) main_arr_ptr[choice - 1]);
                        } else {
                            cout << "There is no value to assign." << endl;
                        }
                        break;
                    }
                    case 6: {
                        int count = 0;
                        for (int i = 0; i < N; i++)
                            if (main_arr_types[i] == main_arr_types[element])
                                count++;
                        if (count > 1) {
                            cout << "Choose value to add:" << endl;
                            for (int i = 0; i < N; i++)
                                if (main_arr_types[i] == main_arr_types[element] && i != element) {
                                    cout << "\t" << i + 1 << ". " << Stroka_type(main_arr_types[i]) <<
                                         "\t" << main_arr_ptr[i]->Str() << endl;
                                }
                            cout << ">";
                            cin >> choice;
                            *((Dec_Stroka *) main_arr_ptr[element]) = *((Dec_Stroka *) main_arr_ptr[element]) +
                                                                     *((Dec_Stroka *) main_arr_ptr[choice - 1]);
                        } else {
                            cout << "There is no value to add." << endl;
                        }
                        break;
                    }
                    case 7: {
                        int count = 0;
                        for (int i = 0; i < N; i++)
                            if (main_arr_types[i] == main_arr_types[element])
                                count++;
                        if (count > 1) {
                            cout << "Choose subtrahend:" << endl;
                            for (int i = 0; i < N; i++)
                                if (main_arr_types[i] == main_arr_types[element] && i != element) {
                                    cout << "\t" << i + 1 << ". " << Stroka_type(main_arr_types[i]) <<
                                         "\t" << main_arr_ptr[i]->Str() << endl;
                                }
                            cout << ">";
                            cin >> choice;
                            *((Dec_Stroka *) main_arr_ptr[element]) = *((Dec_Stroka *) main_arr_ptr[element]) -
                                                                     *((Dec_Stroka *) main_arr_ptr[choice - 1]);
                        } else {
                            cout << "There is no value to subtract." << endl;
                        }
                        break;
                    }
                    case 8: {
                        int count = 0;
                        for (int i = 0; i < N; i++)
                            if (main_arr_types[i] == main_arr_types[element])
                                count++;
                        if (count > 1) {
                            cout << "Choose value to compare with:" << endl;
                            for (int i = 0; i < N; i++)
                                if (main_arr_types[i] == main_arr_types[element] && i != element) {
                                    cout << "\t" << i + 1 << ". " << Stroka_type(main_arr_types[i]) <<
                                         "\t" << main_arr_ptr[i]->Str() << endl;
                                }
                            cout << ">";
                            cin >> choice;
                            cout << (*((Dec_Stroka *) main_arr_ptr[element]) ==
                            *((Dec_Stroka *) main_arr_ptr[choice - 1]) ? "true" : "false") << endl;
                        } else {
                            cout << "There is no value to compare." << endl;
                        }
                        break;
                    }

                    default:
                        cout << "You chosen the number that is not supported. Try again.\n" << endl;
                }
                break;
            }
            default:
                cout << "Element has no type. Do you want to set operand? (Yes/No):\n>";

        }
    }
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