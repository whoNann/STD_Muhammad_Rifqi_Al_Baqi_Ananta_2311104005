#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    stack S;
    createStack(S);

    int lastDigit = 5; 
    
    cout << "Digit terakhir NIM MOD 4 sisa " << lastDigit % 4 << " :" << endl;
    if (lastDigit % 4 == 1) {        
        push(S, 'H');
        push(S, 'A');
        push(S, 'L');
        push(S, 'O');
        push(S, 'B');
        push(S, 'A');
        push(S, 'N');
        push(S, 'D');
        push(S, 'U');
        push(S, 'N');
        push(S, 'G');

        cout << "Output:" << endl;
        printStack(S);
        
        popMultiple(S, 4);
        cout << "Output setelah pop:" << endl;
        printStack(S);
    }
    return 0;
}