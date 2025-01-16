#include <stdio.h>
#include <stdlib.h>
#define max 25
void bfs(int adj[][max], int num)
{
    int queue[max], visited[max];
    int s, rear = 0, front = 0;
    for (int i = 0; i < num; i++)
    {
        visited[i] = 0;
    }
    printf("\nEnter the starting vertex: ");
    scanf("%d", &s);
    queue[rear++] = s;
    visited[s] = 1;
    while (front < rear)
    {
        s = queue[front++];
        printf("%d->",s);
        for (int i = 0; i < num; i++)
        {
            if (adj[s][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
void main()
{
    int adj[max][max] = {0};
    int num;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &num);

    printf("\nEnter the adjcancey matrix: ");
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
        {
            if (i == j)
            {
                adj[i][j] = 1;
            }
            else
            {
                printf("\nEnter Adj[%d][%d]: ", i, j);
                scanf("%d", &adj[i][j]);
            }
        }
    bfs(adj, num);
}