#include <stdio.h>
#include <stdlib.h>

struct SLL {
    int usn;
    char name[30];
    char branch[4];
    int sem;
    char phno[11];
    struct SLL *link;
};

// Function to create a new node
struct SLL* getnode() {
    struct SLL *newnode = (struct SLL*)malloc(sizeof(struct SLL));
    if (newnode == NULL) {
        printf("Memory overflow\n");
        return NULL;
    }
    printf("Enter USN, Name, Branch, Sem, Phone Number: ");
    scanf("%d %s %s %d %s", &newnode->usn, newnode->name, newnode->branch, &newnode->sem, newnode->phno);
    newnode->link = NULL;
    return newnode;
}

// Function to insert a node at the front
void insert_front(struct SLL **start) {
    struct SLL *newnode = getnode();
    if (newnode) {
        newnode->link = *start;
        *start = newnode;
    }
}

// Function to insert a node at the end
void insert_end(struct SLL **start) {
    struct SLL *newnode = getnode();
    if (newnode) {
        if (*start == NULL) {
            *start = newnode;
        } else {
            struct SLL *temp = *start;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = newnode;
        }
    }
}

// Function to delete a node from the front
void delete_front(struct SLL **start) {
    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct SLL *temp = *start;
    *start = temp->link;
    printf("Deleted: %d %s %s %d %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
    free(temp);
}

// Function to delete a node from the end
void delete_end(struct SLL **start) {
    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct SLL *temp = *start, *prev = NULL;
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    if (prev == NULL) { // Only one node
        *start = NULL;
    } else {
        prev->link = NULL;
    }
    printf("Deleted: %d %s %s %d %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
    free(temp);
}

// Function to display the list
void display(struct SLL *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct SLL *temp = start;
    printf("The details are:\n");
    int count = 0;
    while (temp != NULL) {
        printf("%d %s %s %d %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        count++;
        temp = temp->link;
    }
    printf("Number of nodes: %d\n", count);
}

// Main function
int main() {
    struct SLL *start = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n1. Insert at Front\n2. Insert at End\n3. Delete from Front\n4. Delete from End\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert_front(&start); break;
            case 2: insert_end(&start); break;
            case 3: delete_front(&start); break;
            case 4: delete_end(&start); break;
            case 5: display(start); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}