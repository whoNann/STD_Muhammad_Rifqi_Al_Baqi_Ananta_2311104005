#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class PengolahanJarak {
private:
    vector<string> namaSimpul;
    vector<vector<int>> matriksJarak;

public:
    void inputSimpul() {
        int jumlahSimpul;
        cout << "Masukkan jumlah simpul: ";
        cin >> jumlahSimpul;

        namaSimpul.resize(jumlahSimpul);
        cout << "Masukkan nama simpul:\n";
        for (int i = 0; i < jumlahSimpul; i++) {
            cout << "Simpul ke-" << (i + 1) << ": ";
            cin >> namaSimpul[i];
        }
    }

    void hitungJarak() {
        int jumlahSimpul = namaSimpul.size();
        matriksJarak.resize(jumlahSimpul, vector<int>(jumlahSimpul, 0));

        cout << "Masukkan jarak antar simpul:\n";
        for (int i = 0; i < jumlahSimpul; i++) {
            for (int j = 0; j < jumlahSimpul; j++) {
                if (i == j) {
                    matriksJarak[i][j] = 0;
                } else {
                    cout << "Jarak dari simpul " << namaSimpul[i] 
                         << " ke simpul " << namaSimpul[j] << ": ";
                    cin >> matriksJarak[i][j];
                }
            }
        }
    }

    void tampilkanMatriksJarak() {
        cout << "\nMatriks Jarak Antar Simpul:\n";
        
        cout << setw(15) << " ";
        for (const auto& simpul : namaSimpul) {
            cout << setw(15) << simpul;
        }
        cout << endl;

        for (size_t i = 0; i < namaSimpul.size(); i++) {
            cout << setw(15) << namaSimpul[i];
            for (size_t j = 0; j < namaSimpul.size(); j++) {
                cout << setw(15) << matriksJarak[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    PengolahanJarak perhitungan;
    
    perhitungan.inputSimpul();
    perhitungan.hitungJarak();
    
    perhitungan.tampilkanMatriksJarak();

    return 0;
}