#include<stdio.h>
#include<string.h>
#define MAX 60

// Define the stack structure
typedef struct {
  char arr[MAX];
  int top;
} stack;

// Initialization of the stack
void init_stack(stack *ps){
  ps->top == -1;
}

// Check whether the stack is empty or not
int empty(stack *ps){
  return (ps->top == -1);
}

// Add an element on the stack
void push(stack *ps, char c){
  if(ps->top == MAX - 1){
    printf("\nStack Overflow.");
    return -1;
  }
  ps->arr[++ps->top] = c;
}

// Delete
int pop(stack *ps){
  if(empty(ps)){
    printf("\nStack Underflow");
    return -1;
  }
  return ps->arr[ps->top--];
}

int main(void){

  stack s;
  char str[MAX];
  init_stack(&s);

  // Input a string
  printf("\nInput a string: ");
  scanf("%[^\n]s", str);
  
  for(int i = 0; i<strlen(str); i++){
    push(&s, str[i]);
  }
  for(int i = 0; i<strlen(str); i++){
    str[i] = pop(&s);
  }
  printf("The reverse string is: %s\n", str);
  return 0;
}
