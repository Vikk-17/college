#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

double compute(char s, double op1, double op2){
    switch(s){
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '$': return (pow(op1,op2));
        default: return 0;
    }
}

int main(){
    int n, top = -1;
    char pos[20],sym;
    double st[20], op1, op2, res;

    printf("Enter the postfix expression: ");
    scanf("%s", pos);
    n = strlen(pos);
    for(int i = 0; i<n; i++){
        sym = pos[i];
        if(isdigit(sym)) st[++top] = sym - '0';
        else {
            op2 = st[top--];
            op1 = st[top--];
            res = compute(sym, op1, op2);
            st[++top] = res;
        }
    }
    res = st[top--];
    printf("\nResult is: %.2f\n", res);
    return 0;
}