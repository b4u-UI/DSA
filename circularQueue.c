#include<stdio.h>
#include<stdbool.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1;
}
bool isFull() {
    if((rear+1) % MAX == front) return true;
    else return false;
}

void enqueue(int data) {
    if(isFull()) {
        printf("The queue is Full.\n");
        return;
    }
    if(front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = data;
}

void dequeue() {
    if(isEmpty()) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if(isEmpty()) {
        printf("The queue is empty.\n");
        return;
    }
    int i = front;
    while(true) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    // enqueue(6); //Queue is full

    dequeue();
    dequeue();

    enqueue(6);
    enqueu(7);

    display();

    return 0;
}