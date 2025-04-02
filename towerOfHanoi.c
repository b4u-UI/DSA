#include<stdio.h>
void towerOfHanoi(int, char, char, char);
int main() {
    int n;
    printf("Enter the no. of disk: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
   
    return 0;
}

void towerOfHanoi(int n, char A, char B, char C) {
     if(n > 0) {
        towerOfHanoi(n-1, A, C, B);
        printf("Move disk %d from %c to %c\n",n, A, C);
        towerOfHanoi(n-1, B, A, C);
    }   
}