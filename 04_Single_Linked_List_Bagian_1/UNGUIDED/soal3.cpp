#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertDepan(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = head;
    head = baru;
}

void insertBelakang(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
}

void hapusNode(int nilai) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == nilai) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void cetakList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

bool cariNode(int nilai) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == nilai)
            return true;
        temp = temp->next;
    }
    return false;
}

int hitungPanjang() {
    int panjang = 0;
    Node* temp = head;
    while (temp != NULL) {
        panjang++;
        temp = temp->next;
    }
    return panjang;
}

int main() {
    insertDepan(10);
    insertBelakang(20);
    insertDepan(5);

    cout << "Linked list: ";
    cetakList();

    if (cariNode(20))
        cout << "Node dengan nilai 20 ditemukan." << endl;
    else
        cout << "Node dengan nilai 20 tidak ditemukan." << endl;

    cout << "Panjang linked list: " << hitungPanjang() << endl;

    return 0;
}