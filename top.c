#include<stdio.h>
#include<stdlib.h>
#define max 50
int adj[max][max]={0};

void topSort(int adj[][max],int num){
    int sorted[max];
    for(int i=0;i<num;i++){
        sorted[i]=0;
    }
    int j=0;
    while(j<num){
        if(!sorted[j]){
            int flag=1;
            for(int i=0;i<num;i++){
                if(adj[i][j]!=0){
                    flag=0;
                    break;
                }
            }
            if(flag){
                sorted[j]=1;;
                printf("%d\t",j);
                for (int k = 0; k < num; k++)
                {
                    adj[j][k]=0;
                }
                j=0;
            }
            else{
                j++;
            }
        }
        else{
            j++;
        }
    }
    for(int i=0;i<num;i++){
        if(!sorted[i]){
            printf("\nThe graph contains cycle!!!");
        }
    }
}
void main(){
    int num;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&num);
    printf("\nEnter the adjacency matrix: ");
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i==j){
                adj[i][j]=0;
            }
            else{
            printf("\nAdj[%d][%d]",i,j);
            scanf("%d",&adj[i][j]);
            }
        }
    }
    topSort(adj,num);
}