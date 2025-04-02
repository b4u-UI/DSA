#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 4

//global variable
int stack_arr[MAX];
int top = -1;
//function declaration
void push(int);
int pop();
void peek();

bool isFull() {
    if (top == MAX - 1) {
        return true;
    } else {
        return false;
    }
}
bool isEmpty() {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}
void print();

//main function
int main () {
    
    push(1);
    push(2);
    push(3);
    push(4);
    
    int data;
    data = pop();
    data = pop();
    
    push(6);
    // push(7);
    peek();
    printf("Element in stack: ");
    print();
    return 0;
}

void push(int data) {
   
    if(isFull()) {
        printf("[WARRNING!!]Stack Overflow\n");
        return;
    }
     top++;
    stack_arr[top] = data;
}

int pop() {
    if(isEmpty()) {
        printf("Stack is empty\n");
        exit(1);
    }
    int value;
    value = stack_arr[top];
    top--;
    
    return value;
}
void peek() {
    if(isEmpty()) {
        printf("stack Empty!!");
        return;
    }

    printf("Top Element: %d", stack_arr[top]);
}
void print() {
    if(isEmpty()) {
        printf("stack is empty");
        return ;
    }
    int i;
    for(i=0; i<=top; i++) {
        printf("%d ", stack_arr[i]);
    }
}