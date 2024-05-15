#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Define the structure for the queue
struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

// Define the structure for the stack
struct Stack {
    struct Queue q;
};

// Function to create an empty queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmptyQueue(struct Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
bool isFullQueue(struct Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to enqueue an element into the queue
void enQueue(struct Queue* q, int value) {
    if (isFullQueue(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmptyQueue(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->data[q->rear] = value;
}

// Function to dequeue an element from the queue
int deQueue(struct Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    enQueue(&(s->q), value);
    // Rotate the queue
    while (s->q.front != s->q.rear) {
        enQueue(&(s->q), deQueue(&(s->q)));
    }
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (isEmptyQueue(&(s->q))) {
        printf("Stack underflow\n");
        return -1;
    }
    return deQueue(&(s->q));
}

// Function to get the top element of the stack
int top(struct Stack* s) {
    if (isEmptyQueue(&(s->q))) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->q.data[s->q.front];
}

// Function to display all elements in the stack
void display(struct Stack* s) {
    if (isEmptyQueue(&(s->q))) {
        printf("Stack is empty\n");
        return;
    }
    struct Queue tempQ;
    initQueue(&tempQ);
    // Copy elements from the stack queue to a temporary queue
    while (!isEmptyQueue(&(s->q))) {
        int value = pop(s);
        enQueue(&tempQ, value);
        printf("%d ", value);
    }
    // Copy elements back from the temporary queue to the stack queue
    while (!isEmptyQueue(&tempQ)) {
        int value = deQueue(&tempQ);
        enQueue(&(s->q), value);
    }
}

int main() {
    int choice, num;
    struct Stack stack;
    initQueue(&(stack.q));

    /*while(1){
        printf("1. Push into the stack\n2. Pop from the stack\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
          case 1:
            printf("Enter the element to push into the stack: ");
            scanf("%d", &num);
            push(&stack, num);
            break;
          
          case 2:
            printf("Popped element from the stack is %d.\n", pop(&stack));
            break;
          */
  /*          case 3:
            printf("All the elemtents of the stack\n");
            display(&stack);
            break;
    */       
    /*      case 4:
            printf("Exit...\n");
            exit(0);
          default:
            printf("Invalid choice:\(\n");
        }
    }
*/ 


    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 4);
    push(&stack, 1);

    printf("Top of the stack: %d\n", top(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Top of the stack after popping: %d\n", top(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Top of the stack after popping: %d\n", top(&stack));
 
    return 0;
}

