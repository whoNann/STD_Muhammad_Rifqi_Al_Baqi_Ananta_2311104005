#include <iostream>
#include <string>
using namespace std;

struct Node {
    int nim;
    string nama;
    Node* next;
};

class SingleLinkedList {
private:
    Node* head;

public:
    // Constructor
    SingleLinkedList() {
        head = NULL;
    }

    // Fungsi untuk mengecek apakah list kosong
    bool isEmpty() {
        return head == NULL;
    }

    // Fungsi untuk menambah data mahasiswa
    void tambahMahasiswa(int nim, string nama) {
        Node* nodeBaru = new Node;
        nodeBaru->nim = nim;
        nodeBaru->nama = nama;
        nodeBaru->next = NULL;

        if (isEmpty()) {
            head = nodeBaru;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }

    // Fungsi untuk mencari mahasiswa berdasarkan NIM
    void cariMahasiswa(int nim) {
        // Cek apakah list kosong
        if (isEmpty()) {
            cout << "List masih kosong! Silahkan tambah data mahasiswa terlebih dahulu." << endl;
            return;
        }

        Node* current = head;
        bool ditemukan = false;

        while (current != NULL) {
            if (current->nim == nim) {
                cout << "Mahasiswa ditemukan!" << endl;
                cout << "NIM: " << current->nim << endl;
                cout << "Nama: " << current->nama << endl;
                ditemukan = true;
                break;
            }
            current = current->next;
        }

        if (!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan" << endl;
        }
    }

    // Fungsi untuk menampilkan semua data (tambahan untuk memudahkan pengecekan)
    void tampilkanSemuaData() {
        if (isEmpty()) {
            cout << "List masih kosong!" << endl;
            return;
        }

        cout << "\nDaftar Semua Mahasiswa:" << endl;
        Node* current = head;
        while (current != NULL) {
            cout << "NIM: " << current->nim << ", Nama: " << current->nama << endl;
            current = current->next;
        }
    }
};

int main() {
    SingleLinkedList list;
    int pilihan, nim;
    string nama;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Cari Mahasiswa" << endl;
        cout << "3. Tampilkan Semua Mahasiswa" << endl;  // Menambah menu baru
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                list.tambahMahasiswa(nim, nama);
                cout << "Data mahasiswa berhasil ditambahkan!" << endl;
                break;

            case 2:
                cout << "Masukkan NIM yang dicari: ";
                cin >> nim;
                list.cariMahasiswa(nim);
                break;

            case 3:
                list.tampilkanSemuaData();
                break;

            case 4:
                cout << "Program selesai!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}