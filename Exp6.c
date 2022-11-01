#include <stdio.h>
#include <stdlib.h>


int n;

void createGraph(int a[][n]){

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            a[i][j] = 0;
        }
    }

}

void addEdge(int a[][n],int i,int j){

    a[i][j] = 1;
    a[j][i] = 1;
}

void printAdjMat(int a[][n]){
    
    printf("The adjacency matrix for the following graph : \n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%d ",a[i][j]);
        }
            printf("\n");
    }
}

void main(){

    printf("Enter the no. of vertices\n");
    scanf("%d",&n);
    int a[n][n];
    int source,destiny,maxEdges;
    maxEdges = n*(n-1);
    createGraph(a);
    for(int i = 0;i<maxEdges;i++){

        printf("Enter edge %d(-1 -1) to quit : ",i);
        scanf("%d%d",&source,&destiny);
        if(source==-1 && destiny==-1){
            break;
        }
        if(source>n||destiny>n||source<0||destiny<0){
            printf("Not a possible edge\n");
            i--;
        }else{
            addEdge(a,source,destiny);
        }



    }

    printAdjMat(a);
}

//For Turbo C
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define n 4



void createGraph(int a[][n]){

    int i,j;
    for(i = 0;i<n;i++){
	for(j = 0;j<n;j++){
	    a[i][j] = 0;
	}
    }

}

void addEdge(int a[][n],int i,int j){

    a[i][j] = 1;
    a[j][i] = 1;
}

void printAdjMat(int a[][n]){

    int i,j;
    printf("The adjacency matrix for the following graph : \n");
    for(i = 0;i<n;i++){
	for(j = 0;j<n;j++){
	    printf("%d ",a[i][j]);
	}
	    printf("\n");
    }
}

void main(){

    int a[n][n];
    int source,destiny,maxEdges,i;
    clrscr();
    maxEdges = n*(n-1);
    createGraph(a);
    for(i = 0;i<maxEdges;i++){

	printf("Enter edge %d(-1 -1) to quit : ",i);
	scanf("%d%d",&source,&destiny);
	if(source==-1 && destiny==-1){
	    break;
	}
	if(source>n||destiny>n||source<0||destiny<0){
	    printf("Not a possible edge\n");
	    i--;
	}else{
	    addEdge(a,source,destiny);
	}



    }

    printAdjMat(a);
    getch();
}
//For turbo c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define n 4



void createGraph(int a[][n]){

    int i,j;
    for(i = 0;i<n;i++){
	for(j = 0;j<n;j++){
	    a[i][j] = 0;
	}
    }

}

void addEdge(int a[][n],int i,int j){

    a[i][j] = 1;
    a[j][i] = 1;
}

void printAdjMat(int a[][n]){

    int i,j;
    printf("The adjacency matrix for the following graph : \n");
    for(i = 0;i<n;i++){
	for(j = 0;j<n;j++){
	    printf("%d ",a[i][j]);
	}
	    printf("\n");
    }
}

void main(){

    int a[n][n];
    int source,destiny,maxEdges,i;
    clrscr();
    maxEdges = n*(n-1);
    createGraph(a);
    for(i = 0;i<maxEdges;i++){

	printf("Enter edge %d(-1 -1) to quit : ",i);
	scanf("%d%d",&source,&destiny);
	if(source==-1 && destiny==-1){
	    break;
	}
	if(source>n||destiny>n||source<0||destiny<0){
	    printf("Not a possible edge\n");
	    i--;
	}else{
	    addEdge(a,source,destiny);
	}



    }

    printAdjMat(a);
    getch();
}
