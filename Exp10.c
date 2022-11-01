#include <stdio.h>

void dfs(int n,int adj[][n],int visited[],int start){

    int stack[n];
    int top = -1;
    for(int i = 0;i<n;i++){
        visited[i]=0;
    }
    stack[++top] = start;
    visited[start] = 1;

    while(top!=-1){
        start = stack[top--];
        printf("%c-",start+65);
        for(int i = 0;i<n;i++){
            if(adj[start][i] && visited[i]==0){
                stack[++top] = i;
                visited[i] = 1;

            }
        }
    }
}

void main(){

    int n,s;
    printf("Enter the no. of vertices\n");
    scanf("%d",&n);
    int visited[n],adj[n][n];
    printf("Enter the adjaceny matrix\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the source : ");
    scanf("%d",&s);
    dfs(n,adj,visited,s);
}

//For Turbo
#include <stdio.h>
#include <conio.h>
#define n 5

void dfs(int adj[][n],int visited[],int start){

    int stack[n];
    int top = -1,i;
    for(i = 0;i<n;i++){
	visited[i]=0;
    }
    stack[++top] = start;
    visited[start] = 1;

    while(top!=-1){
	start = stack[top--];
	printf("%c-",start+65);
	for(i = 0;i<n;i++){
	    if(adj[start][i] && visited[i]==0){
		stack[++top] = i;
		visited[i] = 1;

	    }
	}
    }
}

void main(){

    int s,i,j;
    int visited[n],adj[n][n];
    clrscr();
    printf("Enter the adjaceny matrix\n");
    for(i = 0;i<n;i++){
	for(j = 0;j<n;j++){
	    scanf("%d",&adj[i][j]);
	}
    }
    printf("Enter the source : ");
    scanf("%d",&s);
    dfs(adj,visited,s);
    getch();
}
//Alternate code:
#include <stdio.h>

#define n 5

void dfs(int i, int adj[][n], int visited[]) {

  printf("%d ", i);
  visited[i] = 1;
  for (int j = 0; j < 5; j++) {
    if (adj[i][j] && !visited[j]) {
      dfs(j, adj, visited);
    }
  }
}

void main() {

  int adj[n][n], vis[n];
  int s, i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", & adj[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    vis[i] = 0;
  }
  printf("Enter source : ");
  scanf("%d", & s);
  dfs(s, adj, vis);

}
