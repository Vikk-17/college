#include<stdio.h>
#define MAX 10
#define INF 999

void dj(int G[MAX][MAX], int n, int startNode){
  int cost[MAX][MAX], pred[MAX], distance[MAX], visited[MAX];
  int count, minDistance, nextNode;
  int i, j;

  // Initialize the cost matrix
  for(i = 0; i<n; i++){
    for(j = 0; j<n; j++){
      if(G[i][j] == 0) cost[i][j] = INF;
      else cost[i][j] = G[i][j];
    }
  }
  // Initialize pred, distance, visited
  for(i = 0; i<n; i++){
    distance[i] = cost[startNode][i];
    visited[i] = 0;
    pred[i] = startNode;
  }
  
  distance[startNode] = 0;
  visited[startNode] = 1;
  count = 1;

  while(count<n-1){
    minDistance = INF;
    for(i = 0; i<n; i++){
      if(distance[i]<minDistance && !visited[i]){
        minDistance = distance[i];
        nextNode = i;
      }
    }
    visited[nextNode] = 1;
    for(i = 0; i<n; i++){
      if(!visited[i]){
        if(minDistance + cost[nextNode][i]< distance[i]){
          distance[i] = minDistance + cost[nextNode][i];
          pred[i] = nextNode;
        }
      }
    }
    count++;
  }

  // print the path
  for(i = 0; i<n;i++){
    if(i!=startNode){
      printf("\nDistance from source to %d: %d", i, distance[i]);
      printf("\nPath=%d", i);
      j = i;

      do{
        j = pred[j];
        printf("<-%d", j);
      }while(j!=startNode);
    }
  }
  printf("\n");
}


int main(){ 
  int G[MAX][MAX], vertices, startNode;

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  printf("Enter the adjacency matrix\n");
  for(int i = 0; i<vertices; i++){
    for(int j = 0; j<vertices; j++){
      scanf("%d", &G[i][j]);
    }
  }
  printf("Enter the source node: ");
  scanf("%d", &startNode);
  
  dj(G, vertices, startNode);
  return 0;
}
