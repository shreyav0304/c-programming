#include<stdio.h>
#define MAX_SIZE 100

void CreateArray(int arr[], int *n) {
    printf("Enter n: ");
    scanf("%d", n);
    for(int i = 0; i < *n; i++)
        scanf("%d", &arr[i]);  
}

void displayArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int *n, int elem, int pos) {
    if(pos < 1 || pos > *n + 1) return;
    for(int i = *n; i >= pos; i--)
        arr[i] = arr[i-1];
    arr[pos - 1] = elem;
    (*n)++;
}

int main() {
    int arr[MAX_SIZE], n = 0, choice, elem, pos;
    while(1) {
        printf("1. Create array\n2. Display array\n3. Insert element\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: CreateArray(arr, &n); break;
            case 2: displayArray(arr, n); break;
            case 3: 
                printf("Enter element and position: ");
                scanf("%d%d", &elem, &pos);
                insertElement(arr, &n, elem, pos); 
                break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
