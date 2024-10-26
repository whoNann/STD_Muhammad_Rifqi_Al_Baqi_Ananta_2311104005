#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct List {
    Node* head;
    Node* tail;
};

void init(List& L) {
    L.head = nullptr;
    L.tail = nullptr;
}

void insertLast_2311104005(List& L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if (L.head == nullptr) {
        L.head = newNode;
        L.tail = newNode;
    } else {
        L.tail->next = newNode;
        newNode->prev = L.tail;
        L.tail = newNode;
    }
}

void tampilDepanBelakang_2311104005(List L) {
    Node* current = L.head;
    cout << "Daftar elemen dari depan ke belakang: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

void tampilBelakangDepan_2311104005(List L) {
    Node* current = L.tail;
    cout << "Daftar elemen dari belakang ke depan: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->prev != nullptr) {
            cout << " <-> ";
        }
        current = current->prev;
    }
    cout << endl;
}

int main() {
    List L;
    init(L);
    
    cout << "Masukkan 4 elemen secara berurutan:" << endl;
    for(int i = 1; i <= 4; i++) {
        int nilai;
        cout << "Masukkan elemen ke-" << i << ": ";
        cin >> nilai;
        insertLast_2311104005(L, nilai);
    }
    
    cout << endl;
    tampilDepanBelakang_2311104005(L);
    tampilBelakangDepan_2311104005(L);
    
    return 0;
}