#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int s[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) printf("\nStack overflow");
    else s[++top] = item;
}

int pop() {
    return top == -1 ? -1 : s[top--];
}

void display() {
    if (top == -1) printf("\n~~~~Stack is empty~~~~");
    else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) printf("%d ", s[i]);
    }
}

void palindrome() {
    int flag = 1;
    for (int i = 0; i <= top / 2; i++) {
        if (s[i] != s[top - i]) flag = 0;
    }
    printf("\nStack content are:\n");
    for (int i = top; i >= 0; i--) printf("%d \n", s[i]);
    printf("\nReverse of stack content are:\n");
    for (int i = 0; i <= top; i++) printf(" %d \n", s[i]);
    printf("\n%s palindrome number", flag ? "It is" : "It is not");
}

int main() {
    int choice, item;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Palindrome\n4.Display\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("\nEnter an element to be pushed:"); scanf("%d", &item); push(item); break;
            case 2: item = pop(); if (item != -1) printf("\nElement popped is: %d", item); break;
            case 3: palindrome(); break;
            case 4: display(); break;
            case 5: exit(1);
            default: printf("\nPlease enter valid choice ");
        }
    }
    return 0;
}