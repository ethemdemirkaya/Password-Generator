#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const char *szSpecial[] = {
        "/","*","-","_","+","(",")","^","!"
};
const char *szAlphabet[] = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
        "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
        "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
};
const char *szDigits[] = {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
};
int main() {
    srand(time(nullptr));
    int iLength = 0;
    int iBitChoice = 0;

    cout << "Olusturulacak sifrenin uzunlugunu giriniz:" << endl;
    cin >> iLength;

    int iChoice = -1;
    while(iChoice != 0) {
        cout << "1) Ozel Karakterler " << ((iBitChoice & (1 << 1)) ? "Olmasin" : "Olsun") << endl;
        cout << "2) Sayilar " << ((iBitChoice & (1 << 2)) ? "Olmasin" : "Olsun") << endl;
        cout << "3) Buyuk Kucuk Harfler " << ((iBitChoice & (1 << 3)) ? "Olmasin" : "Olsun") << endl << endl;
        cout << "0) Kaydet ve Olustur" <<  endl;
        cin >> iChoice;
        if(iChoice != 0) {
            if((iBitChoice & (1 << iChoice))) {
                iBitChoice &= ~(1 << iChoice);
            }
            else {
                iBitChoice |= (1 << iChoice);
            }
        }
    }
    string szPassword;
    for (int i = 0; i < iLength; ++i) {
        int type = rand() % 3;
        switch(type) {
            case 0:
                if (iBitChoice & (1 << 1)) {
                    continue;
                }
                szPassword += szSpecial[rand() % (sizeof(szSpecial) / sizeof(szSpecial[0]))];
                break;
            case 1:
                if (iBitChoice & (1 << 2)) {
                    continue;
                }
                szPassword += szDigits[rand() % (sizeof(szDigits) / sizeof(szDigits[0]))];
                break;
            case 2:
                if (iBitChoice & (1 << 3)) {
                    continue;
                }
                szPassword += szAlphabet[rand() % (sizeof(szAlphabet) / sizeof(szAlphabet[0]))];
                break;
        }
    }

    cout << "Olusturulan sifre: " << szPassword << endl;


    return 0;
}
