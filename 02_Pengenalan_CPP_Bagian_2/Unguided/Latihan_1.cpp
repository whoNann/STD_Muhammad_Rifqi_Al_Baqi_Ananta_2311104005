#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nData Array : ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Nomor Genap : ";
    for (int num : arr) {
        if (num % 2 == 0) {
            cout << num << ", ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil: ";
    for (int num : arr) {
        if (num % 2 != 0) {
            cout << num << ", ";
        }
    }
    cout << endl;

    return 0;
}