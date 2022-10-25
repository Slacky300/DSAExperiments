#include <stdio.h>


void bfs(int y,int x,int a[],int g[][x]);

void main(){

    int n,start;
    printf("Enter the no. of vertices : ");
    scanf("%d",&n);
    int graph[n][n],visited[n];
    printf("Enter the adjacency matrix \n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        visited[i] = 0;
    }
    printf("Enter starting point ");
    scanf("%d",&start);
    bfs(start,n,visited,graph);
}

void bfs(int y,int x,int a[],int g[][x]){

    printf("%d ",y);
    a[y] = 1;
    for(int k = 0;k<x;k++){
        if(!a[k] && g[y][k]==1){
            bfs(k,x,a,g);
        }
    }

}
