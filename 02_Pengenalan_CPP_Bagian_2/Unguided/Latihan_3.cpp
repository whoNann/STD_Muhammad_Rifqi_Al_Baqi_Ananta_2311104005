#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100; // Ukuran maksimum array
    int arr[MAX_SIZE];
    int n, pilihan;

    cout << "Masukkan jumlah elemen array (maksimum 100): ";
    cin >> n;

    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Hitung nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih operasi (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) {
                        max = arr[i];
                    }
                }
                cout << "Nilai maksimum: " << max << endl;
                break;
            }
            case 2: {
                int min = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] < min) {
                        min = arr[i];
                    }
                }
                cout << "Nilai minimum: " << min << endl;
                break;
            }
            case 3: {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                float rata = (float)sum / n;
                cout << "Nilai rata-rata: " << rata << endl;
                break;
            }
            case 4:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}