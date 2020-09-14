#include "Dec_Stroka.h"


Dec_Stroka::Dec_Stroka(): Stroka('0') {
    cout << "Dec_Stroka::Dec_Stroka()" << endl;
}

Dec_Stroka::Dec_Stroka(const char * str): Stroka(str) {
    if ((pch[0] >= '0' && pch[0] <= '9')
        || pch[0] == '+' || pch[0] == '-') {
        for (int i = 1; i < len; i++) {
            if (!(pch[i] >= '0' && pch[i] <= '9')) {
                delete[] pch;
                len = 0;
                pch = new char[len + 2];
                pch[0] = '0';
                pch[1] = '\0';
                cout << "\t__Bad Symbol!__" << endl;
                break;
            }
        }
    }
    else {
        delete[] pch;
        len = 0;
        pch = new char[len + 2];
        pch[0] = '0';
        pch[1] = '\0';
        cout << "\t__Bad Symbol!__" << endl;
    }
    cout << "Dec_Stroka::Dec_Stroka(const char * str)" << endl;
}

Dec_Stroka::Dec_Stroka(const Dec_Stroka & from): Stroka(from) {
    cout << "Dec_Stroka::Dec_Stroka(const Dec_Stroka & from)" << endl;
}

Dec_Stroka::~Dec_Stroka() {
    cout << "Dec_Stroka::~Dec_Stroka()" << endl;
}

const char * Dec_Stroka::Sign() {
    if (pch[0] == '-')
        return "-";
    else
        return "+";
}

Dec_Stroka & Dec_Stroka::operator=(const Dec_Stroka & DS) {
    if (&DS != this) {
        delete[] pch;
        len = strlen(DS.pch);
        pch = new char[len + 1];
        strcpy_s(pch, strlen(pch), DS.pch);
    }
    cout << "Dec_Stroka & Dec_Stroka::operator=(const Dec_Stroka & DS)" << endl;
    return * this;
}

Dec_Stroka::operator int() const {
    int res = 0;
    for (int i = 0; i < len; i++) {
        if (pch[i] == '-' || pch[i] == '+') continue;
        res *= 10;
        res += pch[i] - 48;
    }
    return (pch[0] == '-') ? -res : res;
}

Dec_Stroka operator+(const Dec_Stroka &num1, const Dec_Stroka &num2) {
    int sum = int(num1) + int(num2);
    const char sign = (sum < 0) ? '-' : '+';
    sum = abs(sum);
    int sum_len = 0;
    for (int s = sum; s > 0; sum_len++)
        s /= 10;
    if (sum == 0) {
        return Dec_Stroka("0");
    } else {
        char *ch_sum = new char[sum_len + 2];
        ch_sum[0] = sign;
        for (int i = 1; i < sum_len + 1; i++) {
            ch_sum[i] = char(sum / pow(10, sum_len - i) + '0');
            sum %= int(pow(10, sum_len - i));
        }
        ch_sum[sum_len + 1] = '\0';
        return Dec_Stroka(ch_sum);
    }
}

Dec_Stroka operator-(const Dec_Stroka &num1, const Dec_Stroka &num2) {
    int sum = int(num1) - int(num2);
    const char sign = (sum < 0) ? '-' : '+';
    sum = abs(sum);
    int sum_len = 0;
    for (int s = sum; s > 0; sum_len++)
        s /= 10;
    if (sum == 0) {
        return Dec_Stroka("0");
    } else {
        char *ch_sum = new char[sum_len + 2];
        ch_sum[0] = sign;
        for (int i = 1; i < sum_len + 1; i++) {
            ch_sum[i] = char(sum / pow(10, sum_len - i) + '0');
            sum %= int(pow(10, sum_len - i));
        }
        ch_sum[sum_len + 1] = '\0';
        return Dec_Stroka(ch_sum);
    }
}

int operator==(const Dec_Stroka &num1, const Dec_Stroka &num2) {
    if (int(num1) - int(num2) == 0)
        return 1;
    else
        return 0;
}
