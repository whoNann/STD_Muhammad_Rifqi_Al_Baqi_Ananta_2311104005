#include <iostream>
using namespace std;
int main()
{
    int var = 10;
    int *ptr = &var;
    cout << "Alamat memori dari var: " << &var << endl;
    cout << "Alamat memori yang disimpan dalam ptr: " << ptr << endl;
    return 0;
}