#include <stdio.h>
#include <stdlib.h>
#define max 20
void dfs(int adj[][max], int s, int visited[], int num)
{
    printf("%d->", s);
    for (int i = 0; i < num; i++)
    {
        if (adj[s][i] == 1 && visited[i] == 0)
        {
            visited[i] = 1;
            dfs(adj, i, visited, num);
        }
    }
}
void main()
{
    int num;
    int adj[max][max] = {0};
    printf("\nEnter the number of vertices: ");
    scanf("%d", &num);
    printf("\nEnter the adjaceny matrix: ");
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
            else
            {
                printf("\nEnter Adj[%d][%d]: ", i, j);
                scanf("%d", &adj[i][j]);
            }
        }
    int s, visited[max];
    for (int i = 0; i < num; i++)
        visited[i] = 0;
    printf("\nEnter the starting vertex: ");
    scanf("%d", &s);
    visited[s] = 1;
    dfs(adj, s, visited, num);
}