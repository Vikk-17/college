#include<stdio.h>
#define MAX 10
 
//Declaration of Double Stack
typedef struct
{
    int top1;
    int top2;
    int arr[MAX];
}DStack; 
 
//Initialization of Double Stack
void init( DStack *ps )
{
    ps->top1 = -1;
    ps->top2 = MAX;
}
 
//Push Operation on Stack1
void pushA( DStack *ps, int item )
{
    if( ps->top2 == ps->top1 + 1 )
    {
        printf("\nStack Overflow Stack1");
        return;
    }
 
    ps->arr[++ps->top1] = item;
 
    printf("\nInserted item in Stack1 : %d",item);  
}
 
//Push Operation on Stack2
void pushB( DStack *ps, int item )
{
    if( ps->top2 == ps->top1 + 1 )
    {
        printf("\nStack Overflow Stack2");
        return;
    }
 
    ps->arr[--ps->top2] = item;
 
    printf("\nInserted item in Stack2 : %d",item);  
}
 
//Pop Operation on Stack1
int popA( DStack *ps)
{
    if( ps->top1 == -1 )
    {
        printf("\nStack Underflow Stack1");
        return -1;
    }
 
    return ps->arr[ps->top1--];
    
}
 
//Pop Operation on Stack2
int popB( DStack *ps )
{
    if( ps->top2 == MAX )
    {
        printf("\nStack Underflow Stack2");
        return -1;
    }
 
    return ps->arr[ps->top2++];
}

int main()
{ 
    int item = 0;
 
    DStack s;
 
    init(&s);
 
    pushA( &s, 10);
    pushA( &s, 20);
    pushA( &s, 30);
    pushB( &s, 40);
    pushB( &s, 50);
    pushB( &s, 60);
 
 
    if( popA(&s) == 0 )
        printf("\nDeleted item From Stack1 : %d",item);
    if( popA(&s) == 0 )
        printf("\nDeleted item From Stack1 : %d",item);
    if( popA(&s) == 0 )
        printf("\nDeleted item From Stack1 : %d",item);
    if( popB(&s) == 0 )
        printf("\nDeleted item From Stack2 : %d",item);
    if( popB(&s) == 0 )
        printf("\nDeleted item From Stack2 : %d",item);
    if( popB(&s) == 0 )
        printf("\nDeleted item From Stack2 : %d",item);
 
    printf("\n");
    return 0;
}
