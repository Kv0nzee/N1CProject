#include "stdlib.h"
#include "stdio.h"

#define  MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

int isFull(){
    return rear == MAX-1;
}

int isEmpty() {
    return front == -1 && rear == -1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is Full\n");
    } else {
        if (isEmpty()) {
            front = rear = 0; // Initialize front and rear if queue is empty
        } else {
            rear++; // Move rear pointer to the next position
        }
        queue[rear] = data;
        printf("Data: %d Enqueued\n", data);
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        exit(0);
    }
    printf("Deleted: %d\n", queue[front]);
    if(front == rear){
        front = rear = -1; // Reset front and rear if there was only one element in the queue
    } else {
        front++; // Move front pointer to the next element
    }
}

void display(){
    if(rear == -1){
        printf("Queue is Empty");
        exit(0);
    }
    for (int i = front; i <= rear; i++){
        printf("%d-\n", queue[i]);
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    enqueue(60);
    enqueue(70);
    display();
}
