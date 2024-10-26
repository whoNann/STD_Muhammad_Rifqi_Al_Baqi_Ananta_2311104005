#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string judul;
    string penulis;
    Node* next;
    Node* prev;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Fungsi untuk mengecek apakah list kosong
    bool isEmpty() {
        return head == NULL;
    }

    // Fungsi untuk menambah buku di akhir list
    void tambahBuku(int id, string judul, string penulis) {
        // Membuat node baru
        Node* nodeBaru = new Node;
        nodeBaru->id = id;
        nodeBaru->judul = judul;
        nodeBaru->penulis = penulis;
        nodeBaru->next = NULL;
        nodeBaru->prev = NULL;

        // Jika list masih kosong
        if (isEmpty()) {
            head = tail = nodeBaru;
            cout << "Buku pertama berhasil ditambahkan!" << endl;
            return;
        }

        // Cek apakah ID sudah ada
        Node* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Error: ID Buku " << id << " sudah ada dalam list!" << endl;
                delete nodeBaru; // Hapus node baru karena tidak jadi digunakan
                return;
            }
            temp = temp->next;
        }

        // Menambah di akhir list
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
        cout << "Buku berhasil ditambahkan di akhir list!" << endl;
    }

    // Fungsi untuk menampilkan buku dari awal ke akhir
    void tampilkanMaju() {
        if (isEmpty()) {
            cout << "List masih kosong! Silahkan tambah buku terlebih dahulu." << endl;
            return;
        }

        cout << "\nDaftar Buku (Awal ke Akhir):" << endl;
        cout << "=============================" << endl;
        Node* current = head;
        int nomor = 1;
        while (current != NULL) {
            cout << "Buku ke-" << nomor << endl;
            cout << "ID: " << current->id << endl;
            cout << "Judul: " << current->judul << endl;
            cout << "Penulis: " << current->penulis << endl;
            cout << "-----------------------------" << endl;
            current = current->next;
            nomor++;
        }
    }

    // Fungsi untuk menampilkan buku dari akhir ke awal
    void tampilkanMundur() {
        if (isEmpty()) {
            cout << "List masih kosong! Silahkan tambah buku terlebih dahulu." << endl;
            return;
        }

        cout << "\nDaftar Buku (Akhir ke Awal):" << endl;
        cout << "=============================" << endl;
        Node* current = tail;
        int nomor = 1;
        while (current != NULL) {
            cout << "Buku ke-" << nomor << endl;
            cout << "ID: " << current->id << endl;
            cout << "Judul: " << current->judul << endl;
            cout << "Penulis: " << current->penulis << endl;
            cout << "-----------------------------" << endl;
            current = current->prev;
            nomor++;
        }
    }

    // Fungsi untuk mencari buku berdasarkan ID (tambahan)
    void cariBuku(int id) {
        if (isEmpty()) {
            cout << "List masih kosong! Silahkan tambah buku terlebih dahulu." << endl;
            return;
        }

        Node* current = head;
        bool ditemukan = false;

        while (current != NULL) {
            if (current->id == id) {
                cout << "\nBuku ditemukan!" << endl;
                cout << "ID: " << current->id << endl;
                cout << "Judul: " << current->judul << endl;
                cout << "Penulis: " << current->penulis << endl;
                ditemukan = true;
                break;
            }
            current = current->next;
        }

        if (!ditemukan) {
            cout << "Buku dengan ID " << id << " tidak ditemukan" << endl;
        }
    }
};

int main() {
    DoubleLinkedList list;
    int pilihan, id;
    string judul, penulis;

    do {
        cout << "\nMenu Manajemen Buku:" << endl;
        cout << "====================" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Buku (Awal ke Akhir)" << endl;
        cout << "3. Tampilkan Buku (Akhir ke Awal)" << endl;
        cout << "4. Cari Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID Buku: ";
                cin >> id;
                cout << "Masukkan Judul Buku: ";
                cin.ignore();
                getline(cin, judul);
                cout << "Masukkan Nama Penulis: ";
                getline(cin, penulis);
                list.tambahBuku(id, judul, penulis);
                break;

            case 2:
                list.tampilkanMaju();
                break;

            case 3:
                list.tampilkanMundur();
                break;

            case 4:
                cout << "Masukkan ID Buku yang dicari: ";
                cin >> id;
                list.cariBuku(id);
                break;

            case 5:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid! Silahkan pilih 1-5." << endl;
        }
    } while (pilihan != 5);

    return 0;
}