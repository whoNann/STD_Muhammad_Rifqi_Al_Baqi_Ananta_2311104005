#include <iostream>
#include "doublelist.h"

using namespace std;

void CreateList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void printInfo(List L) {
    address P = L.first;
    if (P == NULL) {
        cout << "List Kosong" << endl;
        return;
    }
    
    while (P != NULL) {
        cout << "Nopol: " << P->info.nopol << endl;
        cout << "Warna: " << P->info.warna << endl;
        cout << "Tahun: " << P->info.thnBuat << endl;
        cout << "------------------------" << endl;
        P = P->next;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

// Fungsi untuk mencari elemen berdasarkan nopol
address findElm(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

// Prosedur delete
void deleteFirst(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
        return;
    }
    
    P = L.first;
    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.first = L.first->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
        return;
    }
    
    P = L.last;
    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.last = L.last->prev;
        L.last->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
        return;
    }
    
    P = Prec->next;
    if (P->next == NULL) { // P adalah elemen terakhir
        Prec->next = NULL;
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
    }
    P->next = NULL;
    P->prev = NULL;
}