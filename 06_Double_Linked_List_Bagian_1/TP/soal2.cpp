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

void deleteFirst_2311104005(List& L) {
    if (L.head == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node* temp = L.head;
    
    if (L.head == L.tail) {  // Jika hanya satu elemen
        L.head = nullptr;
        L.tail = nullptr;
    } else {
        L.head = L.head->next;
        L.head->prev = nullptr;
    }
    
    delete temp;
}

void deleteLast_2311104005(List& L) {
    if (L.head == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node* temp = L.tail;
    
    if (L.head == L.tail) {  // Jika hanya satu elemen
        L.head = nullptr;
        L.tail = nullptr;
    } else {
        L.tail = L.tail->prev;
        L.tail->next = nullptr;
    }
    
    delete temp;
}

void tampilList(List L) {
    Node* current = L.head;
    cout << "DAFTAR ANGGOTA LIST: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    List L;
    init(L);
    
    int nilai;
    
    cout << "Masukkan elemen pertama = ";
    cin >> nilai;
    insertLast_2311104005(L, nilai);
    
    cout << "Masukkan elemen kedua di akhir = ";
    cin >> nilai;
    insertLast_2311104005(L, nilai);
    
    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> nilai;
    insertLast_2311104005(L, nilai);
    
    cout << "\nList sebelum penghapusan:" << endl;
    tampilList(L);
    
    cout << "\nMenghapus elemen pertama dan terakhir..." << endl;
    deleteFirst_2311104005(L);
    deleteLast_2311104005(L);
    
    cout << "\nDaftar anggota list setelah penghapusan:" << endl;
    tampilList(L);
    
    return 0;
}