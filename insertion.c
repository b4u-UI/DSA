#include<stdio.h>
#define MAX 10
void display(int arr[]);
int main() {
	int arr[MAX] = {2, 5, 2, 8, 5, 6, 8, 7, 10, 3};
	int i, j, key;
	for(j=1; j<MAX; j++) {
		key = arr[j];
		i = j-1;
		while(i >= 0 && arr[i] > key) {
			arr[i+1] = arr[i];
			i = i-1;
		}
		arr[i+1] = key;
	}
	printf("Sorted Element: ");
	display(arr);
	return 0;
}
void display(int arr[]){
	int i;
	for(i=0; i<MAX; i++) {
		printf("%d ", arr[i]);
	}	
}
