#include<stdio.h>
#define INF 999
#define MAX 10


void dijkstra(int G[MAX][MAX], int n, int startnode){
    int cost[MAX][MAX], pred[MAX], distance[MAX], visited[MAX];
    int count, mindistance, nextnode;
    int i, j;

    // initialize the cost matrix
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            if(G[i][j] == 0) cost[i][j] = INF;
            else cost[i][j] = G[i][j];
        }
    }

    // initialize the visited, pred and distance array
    for(i = 0; i<n; i++){
        visited[i] = 0;
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
    }
    // distance from startnode
    distance[startnode] = 0;
    // visited the startnode already
    visited[startnode] = 1;

    // number of visited node
    count = 1;
    
    // finding minimum path
    while(count < n-1){
        mindistance = INF;
        for(i = 0; i<n; i++){ // 0->4; the value of i will be = 5
            if(distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        // find if better path is exist
        visited[nextnode] = 1;
        for(i = 0; i<n; i++){
            if(!visited[i]){
                if(cost[nextnode][i] + mindistance < distance[i]){
                    distance[i] = cost[nextnode][i] + mindistance;
                    pred[i] = nextnode; 
                }
            }
        }
        count ++;
    }

    // print the path
    for(i = 0; i<n; i++){
        if(i!=startnode){
            printf("\nDistance from source to %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
        
            do{
                j = pred[j];
                printf("<-%d", j);
            } while(j!=startnode);
        }
    }
}


int main(){
    int G[MAX][MAX], n, startnode;
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the matrix: ");
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++) scanf("%d", &G[i][j]);
    }
    printf("Enter the starting node: ");
    scanf("%d", &startnode);

    dijkstra(G, n, startnode);

    return 0;
}


/*

G matrix:                 Cost matrix
0 10 0 30 100           999 10 999 30 100
10 0 50 0 0             10 999 50 999 999
0 50 0 20 10       =>  999 50 999 20 100
30 0 20 0 60
100 0 10 60 0

*/





