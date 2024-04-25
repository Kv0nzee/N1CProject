#include "stdio.h"
#include "stdlib.h"

#define max_size 10

struct st{
    int items[max_size];
    int top;
};

void initialize(struct st *stack){
    stack->top = -1;
}

int isFull(struct st * stack){
    return (stack->top == max_size -1);
}

int isEmpty(struct st * stack){
    return (stack->top == -1);
}

void push(struct st *stack, int value){
    if(isFull(stack)){
        printf("Stack is Full!\n");
        exit(1);
    }else{
        stack->items[++stack->top] = value;
        printf("value inserted to place->%d : Value:%d\n", stack->top, stack->items[stack->top]);
    }
}

int pop(struct st *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow!\n");
        return -1;
    }else{
        printf("Stack top data removed!\n");
        return stack->items[stack->top--];
    }
}

int peek(struct st *stack){
    if(isFull(stack)){
        printf("Stack have no data!\n");
        return -1;
    }else{
        printf("Top is at %d : Value:%d\n", stack->top, stack->items[stack->top]);
    }
}


int main(){
    struct st stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    peek(&stack);
    pop(&stack);
    peek(&stack);

    push(&stack, 50);
    push(&stack, 60);
    push(&stack, 70);
    push(&stack, 80);


    return 0;

}
