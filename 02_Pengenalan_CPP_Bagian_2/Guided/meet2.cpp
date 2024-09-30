// #include <iostream>
// #include <conio.h>
// using namespace std;

// int main () {
//     int x,y;
//     int *px;
//     x = 87;
//     px = &x;
//     y = *px;


//     cout<<"Alamat x= "<<&x<<endl;
//     cout<<"Isi px= "<<px<<endl;
//     cout<<"Isi X= "<<x<<endl;
//     cout<<"Nilai yang ditunjuk px= "<<*px<<endl;
//     cout<<"Nilai y= "<<y<<endl;
//     getch();
//     return 0;
// }



// #include <iostream>
// #include <conio.h>
// #define MAX 5

// using namespace std;

// int main() {
//     int i, j;
//     float nilai_total, rata_rata;
//     float nilai[MAX];

//     static int nilai_tahun[MAX][MAX] = {
//         {0, 2, 2, 0, 0},
//         {0, 1, 1, 1, 0},
//         {0, 3, 3, 3, 0},
//         {4, 4, 0, 0, 4},
//         {5, 0, 0, 0, 5}
//     };

//     for (i = 0; i < MAX; i++) {
//         cout << "Masukkan nilai ke-" << i + 1 << endl;
//         cin >> nilai[i];
//     }

//     cout << "\nData nilai siswa:\n";
//     for (i = 0; i < MAX; i++) {
//         cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl;
//     }

//     cout << "\nNilai tahunan:\n";
//     for (i = 0; i < MAX; i++) {
//         for (j = 0; j < MAX; j++) {
//             cout << nilai_tahun[i][j] << " ";
//         }
//         cout << "\n";
//     }

//     // getch();
//     return 0;
// }




// #include <iostream>
// #include <cstdlib>  // untuk system("cls")
// #include <conio.h>  // untuk getche()

// using namespace std;

// // Mendeklarasikan prototype fungsi
// int maks3(int a, int b, int c);

// int main() {
//     system("cls");

//     int x, y, z;
//     cout << "Masukkan nilai bilangan ke-1 = ";
//     cin >> x;
//     cout << "Masukkan nilai bilangan ke-2 = ";
//     cin >> y;
//     cout << "Masukkan nilai bilangan ke-3 = ";
//     cin >> z;

//     cout << "Nilai maksimumnya adalah = " << maks3(x, y, z) << endl;
    
//     getche();
//     return 0;
// }

// // Badan fungsi
// int maks3(int a, int b, int c) {
//     // Deklarasi variabel lokal dalam fungsi
//     int temp_max = a;

//     if (b > temp_max)
//         temp_max = b;
//     if (c > temp_max)
//         temp_max = c;

//     return temp_max;
// }




#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void tulis(int x);

int main() {
    system("cls");

    int jum;
    cout << "Jumlah baris kata = ";
    cin >> jum;

    tulis(jum);

    getche();
    return 0;
}

void tulis(int x) {
    for (int i = 0; i < x; i++)
        cout << "Baris ke " << i + 1 << endl;
}