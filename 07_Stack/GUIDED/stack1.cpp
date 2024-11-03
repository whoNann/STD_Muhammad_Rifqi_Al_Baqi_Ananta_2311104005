#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return top == maksimal;
}

bool isEmpty() {
    return top == 0;
}

void pushArrayBuku (string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top -1] == " ";
        top--;
    }
}

void peekArrayBuku (int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top - posisi;
        if (index >= 0 && index < top) {
            cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
        } else {
            cout << "Posisi diluar jangkuan" << endl;
        }
    }
}

int countStcak(){
    return top;
}

void changeArrayBuku (int posisi, string data) {
    int index = top - posisi;
    if (index >= 0 && index < top) {
        arrayBuku[index] = data;
    } else {
        cout << "Posisi melebihi data yang ada" << endl;
    }
}

void destroyArrayBuku() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = " ";
    }
    top = 0;
}

void cetakArrayBuku () {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top -1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main () {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n" << endl;

    cout << "Apakah data stack penuh? " << (isFull() ? "Ya" : "Tidak" ) << endl;
    cout << "Apakah data stack kosong? " << (isFull() ? "Ya" : "Tidak" ) << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStcak() << endl;

    changeArrayBuku(2, " Bahasa Jerman ");
    cetakArrayBuku();
    cout << "\n" << endl;

    destroyArrayBuku();
    cout << "Top setelah destroy: " << top << endl;
    cetakArrayBuku();

    return 0; 
}