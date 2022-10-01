#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *next;

}*head = NULL;

void push(){

    int n;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to add into the stack\n");
    scanf("%d",&n);
    temp->data = n;
    if(head == NULL){
        head = temp;
        temp->next = NULL;
    }else{
        temp->next = head;
        head = temp;
    }
        printf("%d element pushed onto the stack\n",n);
}

void pop(){

    int item;
    struct node *ptr;
    if(head ==NULL){
        printf("Stack Underflow\n");
    }else{
        item = head->data;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("%d element popped\n",item);
    }
}

void display(){

    int m;
    struct node *p;
    p = head;
    if(p==NULL){
        printf("Stack is empty\n");

    }else{
        printf("Stack elements are : \n");
        while(p!=NULL){
            printf("%d\n",p->data);
            p = p->next;
        }
    }
}

void peek(){
    printf("Top element is %d\n",head->data);
}

void main(){

    int ch = 0;
    printf("--------Stack Operations-------\n");
    while(1){
        printf("1.Pop\n2.Push\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&ch);
        if(ch==1){
            pop();
        }else if(ch==2){
            push();
        }else if(ch==3){
            peek();
        }else if(ch==4){
            display();
        }else if(ch==5){
            break;
        }else{
            printf("Invalid choice\n");
        }

    }

        printf("-------End of Stack Operations-----\n");
}
