#include <iostream>
using namespace std;

string angkaKeTulisan(int angka) {
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
    
    if (angka == 0) {
        return "nol";
    }
    
    if (angka < 10) {
        return satuan[angka];
    }
    
    if (angka >= 10 && angka < 20) {
        return belasan[angka - 10];
    }
    
    if (angka >= 20 && angka < 100) {
        int puluhan_bagian = angka / 10;
        int satuan_bagian = angka % 10;
        
        if (satuan_bagian == 0) {
            return puluhan[puluhan_bagian];
        } else {
            return puluhan[puluhan_bagian] + " " + satuan[satuan_bagian];
        }
    }

    if (angka == 100) {
        return "seratus";
    }

    return "Angka di luar jangkauan.";
}

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    string hasil = angkaKeTulisan(angka);

    cout << "Angka " << angka << " dalam tulisan adalah: " << hasil << endl;

    return 0;
}
