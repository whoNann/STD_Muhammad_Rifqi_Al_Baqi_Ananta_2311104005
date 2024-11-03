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
    bool isPalindrom = true;
    
    cout << "Masukan Kalimat : ";
    getline(cin, kalimat);
    
    buatStackKosong(S);
    
    for(int i = 0; i < kalimat.length(); i++) {
        if(kalimat[i] != ' ') {
            pushKarakter(S, kalimat[i]);
        }
    }
    
    for(int i = 0; i < kalimat.length(); i++) {
        if(kalimat[i] != ' ') {
            if(popKarakter(S) != kalimat[i]) {
                isPalindrom = false;
                break;
            }
        }
    }
    
    cout << "Kalimat tersebut adalah : ";
    if(isPalindrom) {
        cout << "Palindrom" << endl;
    } else {
        cout << "bukan Palindrom" << endl;
    }
    
    return 0;
}