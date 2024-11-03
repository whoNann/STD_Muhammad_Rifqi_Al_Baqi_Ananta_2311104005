#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 15 

struct stack {
    char info[MAX_SIZE];
    int top;
};

void createStack(stack &S);
bool isFull(stack S);
void push(stack &S, char x);
bool isEmpty(stack S);
void pop(stack &S);
void printStack(stack S);
void popMultiple(stack &S, int count);

#endif