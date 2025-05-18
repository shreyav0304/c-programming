#include <stdio.h>
#define SIZE 3  
int S[SIZE];   
int top = -1;

void push() {
    int item;
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &item);
    top = top + 1;
    S[top] = item;
}

void pop() { 
    if (top == -1) {
        printf("Stack empty\n");
        return;
    }
    printf("\nDeleted item = %d", S[top]);
    top = top - 1;
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) { 
        printf("%d ", S[i]);  
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Enter 1 to add element:\n2. Enter 2 to remove element:\n3. Enter 3 to display element:\n4. Enter 4 to exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0; 
            default:
                printf("Entered wrong number\n");
                break;
        }
    }
    return 0;
}
