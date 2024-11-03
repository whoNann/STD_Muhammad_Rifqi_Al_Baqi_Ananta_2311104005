#include <iostream>
#include "stack.h"

using namespace std;

void createStack(stack &S) {
    S.top = -1;
}

bool isFull(stack S) {
    return S.top == MAX_SIZE - 1;
}

void push(stack &S, char x) {
    if (isFull(S)) {
        cout << "Stack overflow" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

bool isEmpty(stack S) {
    return S.top == -1;
}

void pop(stack &S) {
    if (!isEmpty(S)) {
        S.top--;
    }
}

void printStack(stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        for (int i = 0; i <= S.top; i++) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void popMultiple(stack &S, int count) {
    for (int i = 0; i < count; i++) {
        if (!isEmpty(S)) {
            pop(S);
        }
    }
}