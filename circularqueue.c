#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert(char c) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full (Overflow)\n");
        return;
    }
    if (front == -1) front = 0; // First insertion
    rear = (rear + 1) % MAX;
    queue[rear] = c;
}

void delete() {
    if (front == -1) {
        printf("Queue is empty (Underflow)\n");
        return;
    }
    printf("Deleted: %c\n", queue[front]);
    if (front == rear) { // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while (i != rear) {
        printf("%c ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%c\n", queue[rear]); // Print the last element
}

int main() {
    int choice;
    char c;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to insert: ");
                scanf(" %c", &c);
                insert(c);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
