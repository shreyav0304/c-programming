#include <stdio.h>
#include <stdlib.h>

struct DLL {
    int usn;
    char name[30];
    char branch[4];
    int sem;
    char phno[11];
    struct DLL *llink, *rlink;
};

struct DLL *start = NULL;

// Function to create a new node
struct DLL* getnode() {
    struct DLL *newnode = (struct DLL*)malloc(sizeof(struct DLL));
    if (newnode == NULL) {
        printf("Memory overflow\n");
        return NULL;
    }
    printf("Enter USN, Name, Branch, Sem, Phone Number: ");
    scanf("%d %s %s %d %s", &newnode->usn, newnode->name, newnode->branch, &newnode->sem, newnode->phno);
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}

// Function to insert a node at the front
void insert_front() {
    struct DLL *newnode = getnode();
    if (newnode) {
        newnode->rlink = start;
        if (start != NULL) {
            start->llink = newnode;
        }
        start = newnode;
    }
}

// Function to insert a node at the end
void insert_end() {
    struct DLL *newnode = getnode();
    if (newnode) {
        if (start == NULL) {
            start = newnode;
        } else {
            struct DLL *temp = start;
            while (temp->rlink != NULL) {
                temp = temp->rlink;
            }
            temp->rlink = newnode;
            newnode->llink = temp;
        }
    }
}

// Function to delete a node from the front
void delete_front() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct DLL *temp = start;
    start = start->rlink;
    if (start != NULL) {
        start->llink = NULL;
    }
    printf("Deleted: %d %s %s %d %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
    free(temp);
}

// Function to delete a node from the end
void delete_end() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct DLL *temp = start;
    while (temp->rlink != NULL) {
        temp = temp->rlink;
    }
    if (temp->llink != NULL) {
        temp->llink->rlink = NULL;
    } else {
        start = NULL; // List had only one node
    }
    printf("Deleted: %d %s %s %d %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
    free(temp);
}

// Function to display the list
void display() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct DLL *temp = start;
    printf("The details are:\n");
    int count = 0;
    while (temp != NULL) {
        printf("%d %s %s %d %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        count++;
        temp = temp->rlink;
    }
    printf("Number of nodes: %d\n", count);
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Insert at Front\n2. Insert at End\n3. Delete from Front\n4. Delete from End\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert_front(); break;
            case 2: insert_end(); break;
            case 3: delete_front(); break;
            case 4: delete_end(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}