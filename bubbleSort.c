#include<stdio.h>
//bubble sorting
int main() {
	int arr[10] = {2, 5, 2, 8, 5, 6, 8, 3, 10, 7};
	int i, j, temp;
	printf("Unsorted Element: ");
	for(i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nSorted Element: ");
	for(i=0; i<10-1; i++) {
		for(j=i; j<10; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(i=0; i<10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
