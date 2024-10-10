#include <iostream>
using namespace std;

int main() {
    // a. Deklarasi dan Inisialisasi Variabel
    int var = 42;
    cout << "a. Nilai var: " << var << endl;
    
    // b. Deklarasi dan Inisialisasi Pointer
    int *ptr = &var;
    cout << "\nb. Pointer ptr menunjuk ke alamat var" << endl;
    
    // c. Menampilkan Alamat Memori
    cout << "\nc. Menampilkan Alamat Memori:" << endl;
    cout << "   Alamat memori dari var: " << &var << endl;
    cout << "   Alamat memori yang disimpan dalam ptr: " << ptr << endl;
    
    // d. Menampilkan Nilai Melalui Pointer
    cout << "\nd. Mengakses Nilai Melalui Pointer:" << endl;
    cout << "   Nilai yang tersimpan pada alamat yang ditunjuk oleh ptr: " << *ptr << endl;
    
    // Demonstrasi tambahan
    cout << "\nDemonstrasi Perubahan Nilai:" << endl;
    cout << "Nilai awal var: " << var << endl;
    *ptr = 100; // Mengubah nilai melalui pointer
    cout << "Nilai var setelah diubah melalui pointer: " << var << endl;
    
    return 0;
}