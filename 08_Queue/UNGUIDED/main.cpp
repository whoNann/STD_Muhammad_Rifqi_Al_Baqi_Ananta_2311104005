#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

class PriorityQueue {
private:
    Node *front;
    int count;
    
public:
    PriorityQueue() {
        front = NULL;
        count = 0;
    }
    
    bool isEmpty() {
        return front == NULL;
    }
    
    void enqueue(string nama, string nim) {
        Node* newNode = new Node;
        newNode->data.nama = nama;
        newNode->data.nim = nim;
        newNode->next = NULL;
        
        if(isEmpty() || nim < front->data.nim) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            while(current->next != NULL && 
                  current->next->data.nim <= nim) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        count++;
    }
    
    void dequeue() {
        if(isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
    }
    
    void viewQueue() {
        if(isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        
        Node* current = front;
        int no = 1;
        cout << "\nData antrian:" << endl;
        while(current != NULL) {
            cout << no << ". Nama: " << current->data.nama 
                 << ", NIM: " << current->data.nim << endl;
            current = current->next;
            no++;
        }
    }
    
    int countQueue() {
        return count;
    }
    
    void clearQueue() {
        while(!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    PriorityQueue q;
    string nama, nim;
    int pilihan;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Hapus Mahasiswa" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Kosongkan Antrian" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM: ";
                getline(cin, nim);
                q.enqueue(nama, nim);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.viewQueue();
                cout << "Jumlah Antrian = " << q.countQueue() << endl;
                break;
            case 4:
                q.clearQueue();
                break;
        }
    } while(pilihan != 0);
    
    return 0;
}