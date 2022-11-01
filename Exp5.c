#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *left,*right;
    int height;

}*root = NULL;


int max(int a,int b)
{

    return (a>b)?a:b;
}

int getHeight(struct node *root)
{

    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}
int getBalanceFactor(struct node *root)
{

    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(root->left) - getHeight(root->right);
    }

}

struct node *newNode(int n)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->right = temp->left = NULL;
    temp->height = 1;
    return temp;
}

struct node *rightRotate(struct node *nodeY)
{

    struct node *nodeX,*hold;
    nodeX = nodeY->left;
    hold = nodeX->right;

    nodeX->right = nodeY;
    nodeY->left = hold;


    nodeY->height = max(getHeight(nodeY->left),getHeight(nodeY->right))+1;
    nodeX->height = max(getHeight(nodeX->left),getHeight(nodeX->right))+1;
    return nodeX;


}

struct node *leftRotate(struct node *nodeX)
{

    struct node *nodeY,*hold;
    nodeY = nodeX->right;
    hold = nodeY->left;

    nodeY->left = nodeX;
    nodeX->right = hold;

    nodeX->height = max(getHeight(nodeX->left),getHeight(nodeX->right))+1;
    nodeY->height = max(getHeight(nodeY->left),getHeight(nodeY->right))+1;
    return nodeY;


}

struct node *insert(struct node *node,int value)
{

    if(node==NULL)
    {
        return newNode(value);
    }
    if(value<node->data)
    {
        node->left = insert(node->left,value);
    }
    else if(value>node->data)
    {
        node->right = insert(node->right,value);
    }
    node->height = 1 + max(getHeight(node->left),getHeight(node->right));

    int bln = getBalanceFactor(node);
    if(bln>1 && value < node->left->data)
    {
        return rightRotate(node);
    }

    if(bln<-1 && value > node->right->data)
    {

        return leftRotate(node);
    }

    if(bln>1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(bln<-1 && value < node->right->data)
    {

        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;


}

void preorder(struct node *root)
{

    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }


}

void postorder(struct node *root)
{

    if(root!=NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }

}


void createTree()
{

    int i,limit,n;
    printf("Enter the no. of nodes you want to enter\n");
    scanf("%d",&limit);
    for(i=0; i<limit; i++)
    {
        printf("Enter the value to add\n");
        scanf("%d",&n);
        root = insert(root,n);
    }


}

void inorder(struct node *root)
{

    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void main()
{

    createTree();
    printf("preOrder : ");
    preorder(root);
    printf("\n");
    printf("posOrder : ");

    postorder(root);
    printf("\n");
    printf("inOrder : ");

    inorder(root);


}




//For Turbo C
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{

    int data;
    struct node *left,*right;
    int height;

}*root = NULL;


int maxT(int a,int b){

    if(a>b){
	return a;
    }else{
	return b;
    }
}

int getHeight(struct node *root)
{

    if(root==NULL)
    {
	return 0;
    }
    else
    {
	return root->height;
    }
}
int getBalanceFactor(struct node *root)
{

    if(root==NULL)
    {
	return 0;
    }
    else
    {
	return getHeight(root->left) - getHeight(root->right);
    }

}

struct node *newNode(int n)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->right = temp->left = NULL;
    temp->height = 1;
    return temp;
}

struct node *rightRotate(struct node *nodeY)
{

    struct node *nodeX,*hold;
    nodeX = nodeY->left;
    hold = nodeX->right;

    nodeX->right = nodeY;
    nodeY->left = hold;


    nodeY->height = maxT(getHeight(nodeY->left),getHeight(nodeY->right))+1;
    nodeX->height = maxT(getHeight(nodeX->left),getHeight(nodeX->right))+1;
    return nodeX;


}

struct node *leftRotate(struct node *nodeX)
{

    struct node *nodeY,*hold;
    nodeY = nodeX->right;
    hold = nodeY->left;

    nodeY->left = nodeX;
    nodeX->right = hold;

    nodeX->height = maxT(getHeight(nodeX->left),getHeight(nodeX->right))+1;
    nodeY->height = maxT(getHeight(nodeY->left),getHeight(nodeY->right))+1;
    return nodeY;


}

struct node *insert(struct node *node,int value)
{
    int bln;
    if(node==NULL)
    {
	return newNode(value);
    }
    if(value<node->data)
    {
	node->left = insert(node->left,value);
    }
    else if(value>node->data)
    {
	node->right = insert(node->right,value);
    }
    node->height = 1 + maxT(getHeight(node->left),getHeight(node->right));

    bln = getBalanceFactor(node);
    if(bln>1 && value < node->left->data)
    {
	return rightRotate(node);
    }

    if(bln<-1 && value > node->right->data)
    {

	return leftRotate(node);
    }

    if(bln>1 && value > node->left->data)
    {
	node->left = leftRotate(node->left);
	return rightRotate(node);
    }

    if(bln<-1 && value < node->right->data)
    {

	node->right = rightRotate(node->right);
	return leftRotate(node);
    }

    return node;


}

void preorder(struct node *root)
{

    if(root!=NULL)
    {
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
    }


}

void postorder(struct node *root)
{

    if(root!=NULL)
    {

	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
    }

}


void createTree()
{

    int i,limit,n;
    printf("Enter the no. of nodes you want to enter\n");
    scanf("%d",&limit);
    for(i=0; i<limit; i++)
    {
	printf("Enter the value to add\n");
	scanf("%d",&n);
	root = insert(root,n);
    }


}

void inorder(struct node *root)
{

    if(root!=NULL)
    {
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
    }
}

void main()
{
    clrscr();
    createTree();
    printf("preOrder : ");
    preorder(root);
    printf("\n");
    printf("posOrder : ");

    postorder(root);
    printf("\n");
    printf("inOrder : ");

    inorder(root);
    getch();

}

















