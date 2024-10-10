#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
