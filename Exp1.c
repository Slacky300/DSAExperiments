#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;

}*head = NULL,*p,*temp;




struct node * addAtEnd(struct node *head,int value)
{


    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=value;
    p = head;
    if(p == NULL)
    {

        head  = temp;
        head->next = NULL;

    }
    else
    {
        while(p->next!=NULL)
        {

            p = p->next;

        }

        p->next = temp;
        temp->next = NULL;
    }


    return head;

}
void display()
{

    p = head;
    if(head==NULL)
    {
        printf("Linked list empty\n");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p = p->next;
        }
    }
    printf("\n");
}

struct node * insertAfter(struct node *head,int value,int hold)
{

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    p = head;
    while(p->data!=hold)
    {

        p = p->next;
        if(p == NULL)
        {
            printf("Value : %d does not exists in the provided linked list\n",value);
            return head;
        }
    }
    temp->next = p->next;
    p->next =  temp;
    return head;


}

struct node * addAtBeg(struct node *head,int value)
{

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = head;
    head = temp;
    return head;
}

struct node * insertAtIndex(struct node *head,int location, int value)
{

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    p = head;
    for(int i = 1; i<location; i++)
    {

        if(p==NULL)
        {
            printf("Linked list exceeded\n");
            return head;
        }

        p = p->next;
    }
    temp->next=p->next;
    p->next  = temp;
    return head;
}
struct node * insertBefore(struct node *head,int value,int hold)
{

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    p = head;
    while(p->next->data!=hold)
    {

        p = p->next;
        if(p == NULL)
        {
            printf("Value : %d does not exists in the provided linked list\n",value);
            return head;
        }
    }

    temp->next = p->next;
    p->next =  temp;
    return head;


}

void removeHead()
{

    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);

}

void removeLast()
{

    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    p = head;
    while(p->next->next!=NULL)
    {
        p = p->next;
    }
    temp =  p->next;
    p->next = NULL;
    free(temp);


}
void deleteSpecific(struct node *head,int value)
{
    struct node *pTail;

    if(value == head->data)
    {

        removeHead();
        return;

    }
    pTail = head;
    p = head;

    while(p->data!=value)
    {

        p = p->next;

    }
    while(pTail->next->data!=value)
    {
        pTail = pTail->next;
    }

    pTail->next=p->next;

    free(p);



}

void main()
{
    printf("Head Insertion : ");
    head = addAtBeg(head,48);
    display();
    printf("After Insertion : ");
    head = insertAfter(head,56,48);
    display();
    printf("Before Insertion : ");
    head = insertBefore(head,72,56);
    display();
    printf("Insert at specified index : ");
    head = insertAtIndex(head,1,92);
    display();
    printf("End Insertion : ");
    head = addAtEnd(head,64);
    display();
    printf("Head deletion : ");
    removeHead();
    display();
    printf("Last element deletion : ");
    removeLast();
    display();
    printf("Specified Element deletion : ");
    deleteSpecific(head,72);
    display();

}
