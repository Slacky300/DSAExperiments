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

        printf("Enter edge %d(0 0) to quit : ",i);
        scanf("%d%d",&source,&destiny);
        if(source==0 && destiny==0){
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
