#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *next;

}*last=NULL;

void insertBeg(int value){

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if(last==NULL){

        last = temp;
        last->next=last;

    }else{
        temp->next = last->next;
        last->next = temp;
    }

}

void insertEnd(int value){

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = last->next;
    last->next = temp;
    last = temp;

}

void addAfter(int value,int item){

    struct node *temp,*p;
    p=last->next;
    do{
        if(p->data==item){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = value;
            temp->next = p->next;
            p->next = temp;
            if(p==last){
                last = temp;
                return;
            }
            return;
        }
        p=p->next;
    }while(p!=last->next);
    printf("%d does not exists in the list\n",item);


}
void addBefore(int value,int item){

    struct node *temp,*p;
    p=last->next;
    do{
        if(p->next->data==item){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = value;
            temp->next = p->next;
            p->next = temp;
            if(p==last){
                last = temp;
                return;
            }
            return;
        }
        p=p->next;
    }while(p!=last->next);

}

void delete(int n){

    struct node *temp,*p;
    if(last==NULL){
        printf("List is empty\n");
        return;
    }
    //deletion of only node in the list;
    if(last->next==last && last->data==n){
        temp = last;
        last = NULL;
        free(temp);
        return;
    }
    //deletion of first node;
    if(last->next->data==n){
        temp = last->next;
        last->next = temp->next;
        free(temp);
        return;
    }
    //deletion of random node;
    p = last->next;
    while(p->next!=last){

        if(p->next->data==n){
            temp = p->next;
            p->next = temp->next;
            free(temp);
            return last;
        }

        p = p->next;

    }
    //deletion of last node;
    if(last->data==n){
        temp = last;
        p->next = last->next;
        last = p;
        free(temp);
        return;
    }
    printf("%d element does not exist in the linked list\n",n);
}


void display(){
    struct node *p;
    p = last->next;
    do{
        printf("%d->",p->data);
        p=p->next;
    }while(p!=last->next);
    printf("\n");
}



void main(){

    insertBeg(47);
    addAfter(87,47);
    addBefore(98,87);
    display();
    delete(87);
    display();
}
