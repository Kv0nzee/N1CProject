#include "stdlib.h"
#include "stdio.h"

struct Node{
    int data;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};

void init(struct Stack* st){
    st->top = NULL;
}

int isEmpty(struct Stack* st){
    return (st->top == NULL);
}

void push(struct  Stack* st, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = st->top;
    st->top = newNode;
    printf("New Node pushed!\n");
}

int pop(struct  Stack* st){
    if(isEmpty(st)){
        printf("Stack underflow!\n");
        exit(1);
    } else{
        struct Node* temp = st->top;
        int data = temp->data;
        st->top = temp->next;
        free(temp);
        return data;
    }
}

int main(){
    struct Stack stack; // Declare a struct Stack object instead of a pointer
    init(&stack); // Pass the address of the stack object

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    pop(&stack);
    pop(&stack);

    push(&stack, 40);

    struct Node* temp = stack.top;
    if (temp != NULL) {
        printf("Top is: %d\n", temp->data);
    } else {
        printf("Stack is empty.\n");
    }

    return 0;
}
