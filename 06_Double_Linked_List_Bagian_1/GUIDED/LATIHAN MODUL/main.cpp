#include <iostream>
#include "doublelist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    
    // Membuat data kendaraan
    kendaraan k1 = {"D001", "Merah", 2020};
    kendaraan k2 = {"D002", "Hitam", 2019};
    kendaraan k3 = {"D003", "Putih", 2021};
    kendaraan k4 = {"D004", "Biru", 2018};
    
    // Menambahkan data ke list
    insertLast(L, alokasi(k1));
    insertLast(L, alokasi(k2));
    insertLast(L, alokasi(k3));
    insertLast(L, alokasi(k4));
    
    cout << "=== Data Awal ===" << endl;
    printInfo(L);
    
    // Mencari kendaraan dengan nopol D001
    cout << "\n=== Mencari Kendaraan D001 ===" << endl;
    address found = findElm(L, "D001");
    if (found != NULL) {
        cout << "Kendaraan ditemukan:" << endl;
        cout << "Nopol: " << found->info.nopol << endl;
        cout << "Warna: " << found->info.warna << endl;
        cout << "Tahun: " << found->info.thnBuat << endl;
    } else {
        cout << "Kendaraan tidak ditemukan" << endl;
    }
    
    // Menghapus kendaraan dengan nopol D003
    cout << "\n=== Menghapus Kendaraan D003 ===" << endl;
    address P = L.first;
    address temp;
    
    while (P != NULL && P->info.nopol != "D003") {
        P = P->next;
    }
    
    if (P != NULL) {
        if (P == L.first) {
            deleteFirst(L, temp);
        } else if (P == L.last) {
            deleteLast(L, temp);
        } else {
            deleteAfter(P->prev, temp);
        }
        cout << "Kendaraan berhasil dihapus" << endl;
    }
    
    cout << "\n=== Data Setelah Penghapusan ===" << endl;
    printInfo(L);
    
    return 0;
}