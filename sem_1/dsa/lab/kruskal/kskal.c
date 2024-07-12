// Find minimum cost spanning tree of a given undirected graph using Kruskal's algorithm

#include<stdio.h>
#define INF 999

int main(){
  int n, a, b, u, v, min;
  int minCost = 0, count = 1;
  int cost[5][5], parent[5] = {0};

  // Read the vertex
  printf("Enter the vertex: ");
  scanf("%d", &n);

  // Read the cost matrix
  printf("Enter the cost matrix\n");
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      printf("Element[%d, %d]: ", i+1, j+1);
      scanf("%d", &cost[i][j]);
      if(cost[i][j] == 0) cost[i][j] = INF;
    } // end for 
  } // end for 

  // Find minimum spanning tree
  while(count < n){
    min = INF;
    for(int i = 0; i<n ; i++){
      for(int j = 0; j<n; j++){
        if(cost[i][j] < min){
          min = cost[i][j];
          a = u = i, b = v = j;
        } // end if 
      } // end for 
    } // end for 
    while(parent[u]) u = parent[u];
    while(parent[v]) v = parent[v];
    if(u != v){
      count ++;
      printf("\nEdge(%d, %d) = %d", a+1, b+1, min);
      minCost += min;
      parent[v] = u;
    } // end if;
    cost[a][b] = cost[b][a] = INF;
  }
  printf("\nMinimum spanning cost: %d", minCost);
  return 0;
}
