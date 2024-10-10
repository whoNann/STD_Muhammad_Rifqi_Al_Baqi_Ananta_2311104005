#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array 2D
void tampilArray(int arr[3][3], string namaArray) {
    cout << "Isi " << namaArray << ":" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Fungsi untuk menukar isi dari 2 array pada posisi tertentu
void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi untuk menukar isi dari variabel yang ditunjuk oleh 2 pointer
void tukarPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // Inisialisasi 2 array 2D
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int array2[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };
    
    // Inisialisasi 2 pointer integer
    int nilai1 = 100;
    int nilai2 = 200;
    int* pointer1 = &nilai1;
    int* pointer2 = &nilai2;
    
    // Menampilkan keadaan awal
    cout << "Keadaan Awal:" << endl;
    tampilArray(array1, "Array 1");
    tampilArray(array2, "Array 2");
    cout << "Nilai Pointer 1: " << *pointer1 << endl;
    cout << "Nilai Pointer 2: " << *pointer2 << endl << endl;
    
    // Menukar isi array pada posisi tertentu (misalnya posisi 1,1)
    cout << "Menukar isi array" << endl;
    tukarIsiArray(array1, array2, 1, 1);
    tampilArray(array1, "Array 1 setelah ditukar");
    tampilArray(array2, "Array 2 setelah ditukar");
    
    // Menukar isi pointer
    cout << "Menukar isi pointer" << endl;
    tukarPointer(pointer1, pointer2);
    cout << "Nilai Pointer 1 setelah ditukar: " << *pointer1 << endl;
    cout << "Nilai Pointer 2 setelah ditukar: " << *pointer2 << endl;
    
    return 0;
}