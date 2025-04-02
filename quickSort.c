#include<stdio.h>

void swap(int *x, int *y);
void quickSort(int arr[], int length);
void quickSort_recursion(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    int arr[10] = {10, 11, 23, 8, 1, 15, 9, 12, 45, 30};
    int length = 10;

    quickSort(arr, length);

    for(int i = 0; i < length; i++) 
        printf("%d ", arr[i]);
    return 0;
}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quickSort(int arr[], int length) {
    quickSort_recursion(arr, 0, length - 1);
}
void quickSort_recursion(int arr[], int low, int high) {
    if(low < high) {
        int pivot_idx = partition(arr, low, high);
        quickSort_recursion(arr,  low, pivot_idx - 1);
        quickSort_recursion(arr,  pivot_idx + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int i = low;
    for(int j = low; j < high; j++) {
        if(arr[j] <= arr[high]) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}