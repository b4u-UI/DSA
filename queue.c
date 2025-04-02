#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 6

int front = -1;
int rear= -1;
int queue[MAX];

bool isFull();
bool isEmpty();
void enqueue(int);
void dequeue();
void display() {
    int i;
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(2);
    enqueue(2);
    enqueue(2);
    enqueue(3);

    display();

    dequeue();
    dequeue();
    dequeue();
}
bool isFull() {
    if(rear == MAX-1) return true;
    else return false;
}
bool isEmpty() {
    if(rear == -1 && front == -1) return true;
    else return false;
}
void enqueue(int data) {
    if(isFull()) {
        printf("Queue is full! Sorry.\n");
        return;
    }
    if(front == -1) {
        front = 0;
    }
    rear ++;
    queue[rear] = data;
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeue %d\n", queue[front]);
    if(front == rear) {
        front = rear = -1;
    } else {
        front ++;
    }

}


