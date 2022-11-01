#include <stdio.h>
#include <ctype.h>

float stack[20];
int top=-1;

void push(float c){

    stack[++top] = c;
}

float pop(){


        return stack[top--];


}

void main(){

    char expression[20];
    char *e;
    float a,b,c;
    printf("Enter the expression : ");
    scanf("%s",expression);
    e = expression;
    while(*e!='\0'){
        if(isdigit(*e)){
            push(*e-48);
        }else{
            a = pop();
            b = pop();
            if(*e=='+'){
                push(b+a);
            }else if(*e=='-'){
                push(b-a);
            }else if(*e=='*'){
                push(a*b);
            }else if(*e=='/'){
                if(a==0){
                    printf("Error divide by zero\n");
                }else{
                    push(b/a);
                }
            }
        }
        e++;
    }

        printf("Result = %f",stack[top]);
}
//For Turbo C
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
float stack[20];
int top=-1;

void push(float c){

    stack[++top] = c;
}

float pop(){


	return stack[top--];


}

void main(){
    char expression[20];
    char *e;
    float a,b,c;
    clrscr();
    printf("Enter the expression : ");
    scanf("%s",expression);
    e = expression;
    while(*e!='\0'){
	if(isdigit(*e)){
	    push(*e-48);
	}else{
	    a = pop();
	    b = pop();
	    if(*e=='+'){
		push(b+a);
	    }else if(*e=='-'){
		push(b-a);
	    }else if(*e=='*'){
		push(a*b);
	    }else if(*e=='/'){
		if(a==0){
		    printf("Error divide by zero\n");
		}else{
		    push(b/a);
		}
	    }
	}
	e++;
    }

	printf("Result = %f",stack[top]);
	getch();
}
