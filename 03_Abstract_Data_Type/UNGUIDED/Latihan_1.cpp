#include <iostream>
#include <string>
using namespace std;

// Jumlah maksimal mahasiswa
const int MAX = 10;

// Deklarasi variabel array untuk menyimpan data
string nama[MAX];
string nim[MAX];
int uts[MAX];
int uas[MAX];
int tugas[MAX];
float nilai_akhir[MAX];
int jumlah_mahasiswa = 0;

// Fungsi untuk menghitung nilai akhir
float hitung_nilai_akhir(int nilai_uts, int nilai_uas, int nilai_tugas) {
    float nilai = 0.3 * nilai_uts + 0.4 * nilai_uas + 0.3 * nilai_tugas;
    return nilai;
}

int main() {
    int pilihan;
    
    do {
        // Tampilkan menu
        cout << "\nProgram Data Mahasiswa\n";
        cout << "1. Tambah Data\n";
        cout << "2. Lihat Data\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            // Tambah data mahasiswa
            if (jumlah_mahasiswa < MAX) {
                cout << "\nMasukkan data mahasiswa ke-" << jumlah_mahasiswa + 1 << endl;
                
                cout << "Nama: ";
                cin.ignore();
                getline(cin, nama[jumlah_mahasiswa]);
                
                cout << "NIM: ";
                getline(cin, nim[jumlah_mahasiswa]);
                
                cout << "Nilai UTS: ";
                cin >> uts[jumlah_mahasiswa];
                
                cout << "Nilai UAS: ";
                cin >> uas[jumlah_mahasiswa];
                
                cout << "Nilai Tugas: ";
                cin >> tugas[jumlah_mahasiswa];
                
                // Hitung nilai akhir
                nilai_akhir[jumlah_mahasiswa] = hitung_nilai_akhir(
                    uts[jumlah_mahasiswa],
                    uas[jumlah_mahasiswa],
                    tugas[jumlah_mahasiswa]
                );
                
                jumlah_mahasiswa++;
                cout << "Data berhasil ditambahkan!\n";
            } else {
                cout << "Maaf, data sudah penuh!\n";
            }
        }
        else if (pilihan == 2) {
            // Tampilkan data mahasiswa
            if (jumlah_mahasiswa > 0) {
                cout << "\nData Mahasiswa:\n";
                for (int i = 0; i < jumlah_mahasiswa; i++) {
                    cout << "\nData ke-" << i + 1 << endl;
                    cout << "Nama: " << nama[i] << endl;
                    cout << "NIM: " << nim[i] << endl;
                    cout << "UTS: " << uts[i] << endl;
                    cout << "UAS: " << uas[i] << endl;
                    cout << "Tugas: " << tugas[i] << endl;
                    cout << "Nilai Akhir: " << nilai_akhir[i] << endl;
                }
            } else {
                cout << "Belum ada data!\n";
            }
        }
        
    } while (pilihan != 3);
    
    cout << "Program selesai!\n";
    
    return 0;
}