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

void deleteRandom(int n){

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
    
    printf("%d element does not exist in the linked list\n",n);
}

void deleteFirst()
{

    struct node *temp;
    if(last==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = last->next;
    last->next = temp->next;
    free(temp);

}

void deleteLast()
{

    struct node *temp,*p;
    p = last->next;
    if(last==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(p->next!=last)
    {
        p = p->next;
    }
    temp = last;
    p->next = last->next;
    last = p;
    free(temp);


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
    insertEnd(49);
    insertEnd(75);
    display();
    deleteRandom(87);
    deleteFirst();
    deleteLast();
    display();
}
