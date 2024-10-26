#include <iostream>
using namespace std;

// Struktur untuk node dalam Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Struktur untuk List
struct List {
    Node* head;
    Node* tail;
};

// Inisialisasi List kosong
void init(List& L) {
    L.head = nullptr;
    L.tail = nullptr;
}

// Fungsi untuk menambah elemen di awal list
void insertFirst_2311104005(List& L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if (L.head == nullptr) {  // Jika list kosong
        L.head = newNode;
        L.tail = newNode;
    } else {  // Jika list tidak kosong
        newNode->next = L.head;
        L.head->prev = newNode;
        L.head = newNode;
    }
}

// Fungsi untuk menambah elemen di akhir list
void insertLast_2311104005(List& L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if (L.head == nullptr) {  // Jika list kosong
        L.head = newNode;
        L.tail = newNode;
    } else {  // Jika list tidak kosong
        L.tail->next = newNode;
        newNode->prev = L.tail;
        L.tail = newNode;
    }
}

// Fungsi untuk menampilkan semua elemen list
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
    insertFirst_2311104005(L, nilai);
    
    cout << "Masukkan elemen kedua di awal = ";
    cin >> nilai;
    insertFirst_2311104005(L, nilai);
    
    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> nilai;
    insertLast_2311104005(L, nilai);
    
    tampilList(L);
    
    return 0;
}