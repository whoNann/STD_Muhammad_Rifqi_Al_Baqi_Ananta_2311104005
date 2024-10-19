#include "list.h"

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x) {
    address P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List L) {
    address P = first(L);
    while (P != NULL) {
        cout << info(P) << " ";
        P = next(P);
    }
    cout << endl;
}