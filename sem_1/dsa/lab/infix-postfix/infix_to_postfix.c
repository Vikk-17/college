#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
    char items[20];
    int top;
} Stack;

void init(Stack *ps){
    ps->top = -1;
}

int empty(Stack *ps){
    if(ps->top == -1) return 1;
    else return 0;
}

char push(char x, Stack *ps){
    ps->items[++ps->top] = x;
}

char pop(Stack *ps){
    return ps->items[ps->top--];
}

char top(Stack *ps){
    return ps->items[ps->top];
}

int priority(char x){
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/' || x == '%') return 2;
    return 3;
}

void postfix(char infix[], char postr[]){
    char symb, x;
    int outpos = 0, position;
    
    Stack s;
    init(&s);
    
    // Traverse the infix expression
    for(position = 0; (symb = infix[position]) != '\0'; position++){
        // check for alphanumeric
        if(isalnum(symb)) postr[outpos++] = symb;
        // check for '('
        else if(symb == '(') push('(', &s);
        // check for ')'
        else if(symb == ')') while((x = pop(&s))!='(') postr[outpos++] = x;
        // check for operator
        else {
            while(priority(symb) <= priority(top(&s)) && !empty(&s)){
                x = pop(&s);
                postr[outpos++] = x;
            }
            push(symb, &s);
        }
    } // end for

    while(!empty(&s)){
        x = pop(&s);
        postr[outpos++] = x;
    }
    postr[outpos] = '\0';

}

int main(){
    char infix[20], postr[20];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    printf("Infix expression is: %s", infix);
    postfix(infix, postr);
    printf("\nPostfix expression is: %s\n", postr);
    return 0;
}