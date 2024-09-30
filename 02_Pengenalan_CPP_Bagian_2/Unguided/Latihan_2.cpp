#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    
    const int MAX = 10;
    
    int arr[MAX][MAX][MAX];
    
    cout << "Masukkan ukuran array 3D (x y z), maks 10 untuk setiap dimensi: ";
    cin >> x >> y >> z;
    
    if (x > MAX || y > MAX || z > MAX) {
        cout << "Ukuran melebihi batas maksimum!" << endl;
        return 1;
    }
    
    cout << "Masukkan elemen array:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "arr[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
    }
    
    cout << "\nArray 3D yang diinputkan:" << endl;
    for (int i = 0; i < x; i++) {
        cout << "Layer " << i + 1 << ":" << endl;
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}