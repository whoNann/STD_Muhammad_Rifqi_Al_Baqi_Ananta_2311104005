#include <iostream>
#include "singlelist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;  // Menghapus inisialisasi NULL
    
    createList(L);
    
    P1 = alokasi(2);
    insertFirst(L, P1);
    
    P2 = alokasi(0);
    insertFirst(L, P2);
    
    P3 = alokasi(8);
    insertFirst(L, P3);
    
    P4 = alokasi(12);
    insertFirst(L, P4);
    
    P5 = alokasi(9);
    insertFirst(L, P5);
    
    cout << "Initial list:" << endl;
    printInfo(L);
    
    address found = findElm(L, 8);
    if (found != NULL) {
        cout << "\nElement with value 8 found at address: " << found << endl;
    } else {
        cout << "\nElement with value 8 not found" << endl;
    }
    
    int total = sumInfo(L);
    cout << "\nSum of all elements: " << total << endl;
    
    return 0;
}