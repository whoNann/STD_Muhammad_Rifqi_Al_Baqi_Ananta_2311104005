#include <iostream>
using namespace std;

int main() {
    float bil1, bil2;
    cout << "Masukkan bilangan pertama: ";
    cin >> bil1;
    cout << "Masukkan bilangan kedua: ";
    cin >> bil2;

    float penjumlahan = bil1 + bil2;
    float pengurangan = bil1 - bil2;
    float perkalian = bil1 * bil2;
    float pembagian = bil1 / bil2;

    cout << "Hasil:" << endl;
    cout << "penjumlahan: "  << penjumlahan << endl;
    cout << "pengurangan: "  << pengurangan << endl;
    cout << "perkalian: " << perkalian << endl;
    cout << "pembagian: " << pembagian << endl;

    return 0;
}