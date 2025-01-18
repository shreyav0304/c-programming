#include <stdio.h>
#define MAX_SIZE 100

void CreateArray(int arr[], int *n) {
    printf("Enter n: ");
    scanf("%d", n);
    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++)
        scanf("%d", &arr[i]);
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int *n, int elem, int pos) {
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = elem;
    (*n)++;
    printf("Element %d inserted at position %d.\n", elem, pos);
}

void deleteElement(int arr[], int *n, int pos) {
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
    printf("Element at position %d deleted.\n", pos);
}

int main() {
    int arr[MAX_SIZE], n = 0, choice, elem, pos;
    while (1) {
        printf("1. Create array\n2. Display array\n3. Insert element\n4. Delete element\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: CreateArray(arr, &n); break;
            case 2: displayArray(arr, n); break;
            case 3:
                printf("Enter element and position: ");
                scanf("%d%d", &elem, &pos);
                insertElement(arr, &n, elem, pos);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            case 5: 
                printf("Exiting the program.\n");
                return 0;
            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}