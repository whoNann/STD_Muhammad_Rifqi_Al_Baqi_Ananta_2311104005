#include "list.h"

int main() {
    List L;
    address P;
    infotype x;

    createList(L);

    cout << "Masukkan 3 digit NIM terakhir:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Digit " << i+1 << ": ";
        cin >> x;
        P = allocate(x);
        insertFirst(L, P);
    }

    cout << "Isi list: ";
    printInfo(L);

    return 0;
}