#include <iostream>
#include <string>
using namespace std;

struct Stack {
    char data[50];
    int top;
};

void buatStackKosong(Stack &S) {
    S.top = -1;
}

void pushKarakter(Stack &S, char karakter) {
    S.top = S.top + 1;
    S.data[S.top] = karakter;
}

char popKarakter(Stack &S) {
    char hasil = S.data[S.top];
    S.top = S.top - 1;
    return hasil;
}

int main() {
    Stack S;
    string kalimat;
    
    cout << "Masukkan Kata : ";
    getline(cin, kalimat);
    
    buatStackKosong(S);
    
    for(int i = 0; i < kalimat.length(); i++) {
        pushKarakter(S, kalimat[i]);
    }
    
    cout << "Datastack Array : " << endl;
    cout << "Data : ";
    
    while(S.top >= 0) {
        cout << popKarakter(S);
    }
    cout << endl;
    
    return 0;
}