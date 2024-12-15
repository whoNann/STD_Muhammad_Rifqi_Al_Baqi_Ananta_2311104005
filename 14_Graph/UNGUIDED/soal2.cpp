#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int jumlahSimpul;
    vector<vector<int>> matriksKetetanggaan;

public:
    Graf(int simpul) {
        jumlahSimpul = simpul;
        matriksKetetanggaan.resize(simpul, vector<int>(simpul, 0));
    }

    void tambahSisi(int simpul1, int simpul2) {
        // Sesuaikan indeks untuk array 0-based
        simpul1--;
        simpul2--;
        
        // Graf tidak berarah, set kedua arah
        matriksKetetanggaan[simpul1][simpul2] = 1;
        matriksKetetanggaan[simpul2][simpul1] = 1;
    }

    void cetakMatriksKetetanggaan() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < jumlahSimpul; i++) {
            for (int j = 0; j < jumlahSimpul; j++) {
                cout << matriksKetetanggaan[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int jumlahSimpul, jumlahSisi;

    // Input jumlah simpul
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    // Buat graf
    Graf graf(jumlahSimpul);

    // Input jumlah sisi
    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;

    // Input sisi
    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < jumlahSisi; i++) {
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;
        graf.tambahSisi(simpul1, simpul2);
    }

    // Cetak matriks ketetanggaan
    graf.cetakMatriksKetetanggaan();

    return 0;
}