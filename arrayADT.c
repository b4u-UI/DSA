#include <stdio.h>

#define SIZE 10

typedef struct {
    int arr[SIZE]; // Fixed size array
    int size;      // Current number of elements
} ArrayADT;

// Initialize the array
void init(ArrayADT *array) {
    array->size = 0;
}

// Insert an element at a specific position
void insert(ArrayADT *array, int element, int position) {
    if (array->size >= SIZE) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    if (position < 0 || position > array->size) {
        printf("Invalid position!\n");
        return;
    }
    // Shift elements to the right
    for (int i = array->size; i > position; i--) {
        array->arr[i] = array->arr[i - 1];
    }
    array->arr[position] = element;
    array->size++;
}

// Delete an element from a specific position
void removeElement(ArrayADT *array, int position) {
    if (position < 0 || position >= array->size) {
        printf("Invalid position! Cannot delete.\n");
        return;
    }
    // Shift elements to the left
    for (int i = position; i < array->size - 1; i++) {
        array->arr[i] = array->arr[i + 1];
    }
    array->size--;
}

// Display the array elements
void display(ArrayADT *array) {
    if (array->size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->arr[i]);
    }
    printf("\n");
}

int main() {
    ArrayADT array;
    init(&array);

    // Testing insert operation
    insert(&array, 10, 0);
    insert(&array, 20, 1);
    insert(&array, 30, 2);
    insert(&array, 40, 3);
    insert(&array, 50, 4);
    display(&array);

    // Testing delete operation
    removeElement(&array, 2); // Removing element at index 2
    display(&array);

    // Inserting more elements
    insert(&array, 60, 2);
    insert(&array, 70, 3);
    display(&array);

    return 0;
}