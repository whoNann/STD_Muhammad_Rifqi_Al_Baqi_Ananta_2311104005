#include <iostream>
#include <string>
using namespace std;

// Kelas untuk menyimpan data proyek
class Proyek {
public:
    string nama_proyek;
    int durasi;
    Proyek* next;

    Proyek(string nama, int durasi) {
        this->nama_proyek = nama;
        this->durasi = durasi;
        this->next = nullptr;
    }
};

// Kelas untuk menyimpan data pegawai
class Pegawai {
public:
    string nama;
    string id_pegawai;
    Proyek* proyek_head;
    Pegawai* next;

    Pegawai(string nama, string id_pegawai) {
        this->nama = nama;
        this->id_pegawai = id_pegawai;
        this->proyek_head = nullptr;
        this->next = nullptr;
    }
};

// Kelas untuk manajemen data pegawai dan proyek
class ManajemenData {
public:
    Pegawai* head;

    ManajemenData() {
        head = nullptr;
    }

    // Menambahkan pegawai baru ke dalam list
    void tambah_pegawai(string nama, string id_pegawai) {
        Pegawai* new_pegawai = new Pegawai(nama, id_pegawai);
        if (!head) {
            head = new_pegawai;
        } else {
            Pegawai* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new_pegawai;
        }
    }

    // Menambahkan proyek baru untuk pegawai tertentu
    void tambah_proyek(string id_pegawai, string nama_proyek, int durasi) {
        Pegawai* temp = head;
        while (temp) {
            if (temp->id_pegawai == id_pegawai) {
                Proyek* new_proyek = new Proyek(nama_proyek, durasi);
                if (!temp->proyek_head) {
                    temp->proyek_head = new_proyek;
                } else {
                    Proyek* proyek_temp = temp->proyek_head;
                    while (proyek_temp->next) {
                        proyek_temp = proyek_temp->next;
                    }
                    proyek_temp->next = new_proyek;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Pegawai dengan ID " << id_pegawai << " tidak ditemukan.\n";
    }

    // Menghapus proyek berdasarkan nama proyek untuk pegawai tertentu
    void hapus_proyek(string id_pegawai, string nama_proyek) {
        Pegawai* temp = head;
        while (temp) {
            if (temp->id_pegawai == id_pegawai) {
                Proyek* proyek_temp = temp->proyek_head;
                Proyek* prev = nullptr;
                while (proyek_temp) {
                    if (proyek_temp->nama_proyek == nama_proyek) {
                        if (prev) {
                            prev->next = proyek_temp->next;
                        } else {
                            temp->proyek_head = proyek_temp->next;
                        }
                        delete proyek_temp;
                        return;
                    }
                    prev = proyek_temp;
                    proyek_temp = proyek_temp->next;
                }
                cout << "Proyek dengan nama " << nama_proyek << " tidak ditemukan.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Pegawai dengan ID " << id_pegawai << " tidak ditemukan.\n";
    }

    // Menampilkan data pegawai dan proyek mereka
    void tampilkan_data() {
        Pegawai* temp = head;
        while (temp) {
            cout << "Pegawai: " << temp->nama << " (ID: " << temp->id_pegawai << ")\n";
            Proyek* proyek_temp = temp->proyek_head;
            if (proyek_temp) {
                cout << "Proyek yang dikelola:\n";
                while (proyek_temp) {
                    cout << "  - " << proyek_temp->nama_proyek << " (Durasi: " << proyek_temp->durasi << " bulan)\n";
                    proyek_temp = proyek_temp->next;
                }
            } else {
                cout << "  Tidak ada proyek.\n";
            }
            cout << endl;
            temp = temp->next;
        }
    }
};

// Program utama
int main() {
    ManajemenData manajemen;

    // 1. Menambahkan pegawai
    manajemen.tambah_pegawai("Andi", "P001");
    manajemen.tambah_pegawai("Budi", "P002");
    manajemen.tambah_pegawai("Citra", "P003");

    // 2. Menambahkan proyek
    manajemen.tambah_proyek("P001", "Aplikasi Mobile", 12);
    manajemen.tambah_proyek("P002", "Sistem Akuntansi", 8);
    manajemen.tambah_proyek("P003", "E-commerce", 10);

    // 3. Menambahkan proyek baru
    manajemen.tambah_proyek("P001", "Analisis Data", 6);

    // 4. Menghapus proyek "Aplikasi Mobile" dari Andi
    manajemen.hapus_proyek("P001", "Aplikasi Mobile");

    // 5. Menampilkan data pegawai dan proyek mereka
    manajemen.tampilkan_data();

    return 0;
}
