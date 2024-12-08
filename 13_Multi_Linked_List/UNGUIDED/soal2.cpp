#include <iostream>
#include <string>
using namespace std;

// Kelas untuk menyimpan data buku
class Buku {
public:
    string judul_buku;
    string tanggal_pengembalian;
    Buku* next;

    Buku(string judul, string tanggal) {
        this->judul_buku = judul;
        this->tanggal_pengembalian = tanggal;
        this->next = nullptr;
    }
};

// Kelas untuk menyimpan data anggota
class Anggota {
public:
    string nama;
    string id_anggota;
    Buku* buku_head;
    Anggota* next;

    Anggota(string nama, string id_anggota) {
        this->nama = nama;
        this->id_anggota = id_anggota;
        this->buku_head = nullptr;
        this->next = nullptr;
    }
};

// Kelas untuk manajemen data anggota dan buku
class ManajemenPerpustakaan {
public:
    Anggota* head;

    ManajemenPerpustakaan() {
        head = nullptr;
    }

    // Menambahkan anggota baru ke dalam list
    void tambah_anggota(string nama, string id_anggota) {
        Anggota* new_anggota = new Anggota(nama, id_anggota);
        if (!head) {
            head = new_anggota;
        } else {
            Anggota* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new_anggota;
        }
    }

    // Menambahkan buku yang dipinjam oleh anggota tertentu
    void tambah_buku(string id_anggota, string judul_buku, string tanggal_pengembalian) {
        Anggota* temp = head;
        while (temp) {
            if (temp->id_anggota == id_anggota) {
                Buku* new_buku = new Buku(judul_buku, tanggal_pengembalian);
                if (!temp->buku_head) {
                    temp->buku_head = new_buku;
                } else {
                    Buku* buku_temp = temp->buku_head;
                    while (buku_temp->next) {
                        buku_temp = buku_temp->next;
                    }
                    buku_temp->next = new_buku;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Anggota dengan ID " << id_anggota << " tidak ditemukan.\n";
    }

    // Menghapus anggota beserta buku yang dipinjam
    void hapus_anggota(string id_anggota) {
        Anggota* temp = head;
        Anggota* prev = nullptr;
        
        while (temp) {
            if (temp->id_anggota == id_anggota) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }

                // Menghapus semua buku yang dipinjam oleh anggota ini
                Buku* buku_temp = temp->buku_head;
                while (buku_temp) {
                    Buku* buku_next = buku_temp->next;
                    delete buku_temp;
                    buku_temp = buku_next;
                }

                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Anggota dengan ID " << id_anggota << " tidak ditemukan.\n";
    }

    // Menampilkan seluruh data anggota dan buku yang dipinjam
    void tampilkan_data() {
        Anggota* temp = head;
        while (temp) {
            cout << "Anggota: " << temp->nama << " (ID: " << temp->id_anggota << ")\n";
            Buku* buku_temp = temp->buku_head;
            if (buku_temp) {
                cout << "Buku yang dipinjam:\n";
                while (buku_temp) {
                    cout << "  - " << buku_temp->judul_buku << " (Pengembalian: " << buku_temp->tanggal_pengembalian << ")\n";
                    buku_temp = buku_temp->next;
                }
            } else {
                cout << "  Tidak ada buku yang dipinjam.\n";
            }
            cout << endl;
            temp = temp->next;
        }
    }
};

// Program utama
int main() {
    ManajemenPerpustakaan perpustakaan;

    // 1. Menambahkan anggota
    perpustakaan.tambah_anggota("Rani", "A001");
    perpustakaan.tambah_anggota("Dito", "A002");
    perpustakaan.tambah_anggota("Vina", "A003");

    // 2. Menambahkan buku yang dipinjam
    perpustakaan.tambah_buku("A001", "Pemrograman C++", "01/12/2024");
    perpustakaan.tambah_buku("A002", "Algoritma Pemrograman", "15/12/2024");

    // 3. Menambahkan buku baru
    perpustakaan.tambah_buku("A001", "Struktur Data", "10/12/2024");

    // 4. Menghapus anggota Dito beserta buku yang dipinjam
    perpustakaan.hapus_anggota("A002");

    // 5. Menampilkan seluruh data anggota dan buku yang dipinjam
    perpustakaan.tampilkan_data();

    return 0;
}
