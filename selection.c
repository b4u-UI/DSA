#include<stdio.h>
#define MAX 10

void swap(int [], int, int);
void display(int []);
int main() {
	int arr[MAX] = {2, 5, 2, 8, 5, 6, 8, 7, 10, 3};
	int min, i, j;
	for(i=0; i<MAX-1; i++) {
		min = i;
		for(j=i+1; j<MAX; j++) {
			if(arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr, min, i);
	}
	display(arr);
	return 0;
}

void swap(int arr[], int min, int i) {
	int temp;
	temp = arr[min];
	arr[min] = arr[i];
	arr[i] = temp;
}
void display(int arr[]) {
	int i;
	for(i=0; i<MAX; i++) {
		printf("%d ", arr[i]);
	}
}
