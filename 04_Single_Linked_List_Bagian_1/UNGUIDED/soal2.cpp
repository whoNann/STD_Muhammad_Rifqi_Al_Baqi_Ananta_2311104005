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

int main() {
    insertDepan(10);
    insertBelakang(20);
    insertDepan(5);

    cout << "Linked list awal: ";
    cetakList();

    hapusNode(10);

    cout << "Linked list setelah menghapus 10: ";
    cetakList();

    return 0;
}