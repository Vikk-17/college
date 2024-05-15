#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int adj[MAX][MAX];

void init(int n){
    for(int i=1;i<=n;i++)
        adj[i][i]=1;
}

// Function to add edge between nodes
void addEdge(int a,int b){
    adj[a][b]=1;
    adj[b][a]=1;
}

void computePaths(int n){
    for(int k = 1; k <= n; k++){
        // Try every vertex as an 
        // intermediate vertex
        // to check if a path exists
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
    }
}

int isReachable(int s, int d)
{
    if (adj[s][d] == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int n = 6;

    init(n);

    addEdge(6, 4);
    addEdge(4, 5);
    addEdge(4, 3);
    addEdge(5, 1);
    addEdge(5, 2);
    addEdge(3, 2);
    addEdge(2, 1);
  

    computePaths(n);

    int u = 3, v = 1;
    if(isReachable(u,v))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
