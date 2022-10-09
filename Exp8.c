#include <stdio.h>
#include <ctype.h>

char stack[30];
int top = -1;

void push(char c){

    stack[++top] = c;

}

char pop(){

    if(top==-1){
        return -1;
    }else{
        return stack[top--];

    }
}

int priority(char c){

    if(c == '('){
        return 0;
    }
    if(c == '+' || c == '-'){
        return 1;
    }
    if(c == '*' || c == '/'){
        return 2;
    }
    if(c == '^'){
        return 3;
    }
}

void main(){

    char expression[20];
    char *e,hold;
    printf("Enter the expression : ");
    scanf("%s",expression);
    e = expression;
    printf("The postfix expression : ");
    while(*e != '\0'){
        if(isalnum(*e)){
            printf("%c",*e);
        }else if(*e=='('){
            push(*e);
        }else if(*e == ')'){
            while((hold=pop()) != '('){
                printf("%c",hold);
            }
        }else{
            while(priority(stack[top])>=priority(*e)){
                printf("%c",pop());
            }
            push(*e);
        }

        e++;
    }
    while(top != -1){
        printf("%c",pop());
    }

}
