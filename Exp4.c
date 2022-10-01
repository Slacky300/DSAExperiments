#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *left,*right;

}*root=NULL;

struct node *newNode(int n){

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->left=temp->right = NULL;
    return temp;

}

struct node *insert(struct node *root,int n){

    if(root==NULL){
        return newNode(n);
    }else if(n>root->data){
        root->right = insert(root->right,n);
    }else{
        root->left = insert(root->left,n);
    }
    return root;

}

void createTree(){

    int i,limit,n;
    printf("Enter the no. of node you want to enter\n");
    scanf("%d",&limit);
    printf("(Note: the first node you enter is considered as a root node)\n");
    for(i=0;i<limit;i++){
        printf("Enter the value to enter\n");
        scanf("%d",&n);
        if(root==NULL){
            root = newNode(n);
        }else{
            insert(root,n);

        }
    }

}

void inorder(struct node *root){

    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){

    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }


}

void postorder(struct node *root){

     if(root!=NULL){

        preorder(root->left);
        preorder(root->right);
        printf("%d ",root->data);
    }

}

void main(){

    createTree();
    printf("Inorder : ");
    inorder(root);
    printf("\n");
    printf("Preorder : ");
    preorder(root);
    printf("\n");
    printf("Postorder : ");
    postorder(root);
    printf("\n");

}


