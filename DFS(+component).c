#include<stdio.h>
void dfs(int);
int a[10][10],visited[10],n;
int main()
{
    int i,j,c=1,s,l;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter adjecency matrix of the graph:");
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        visited[i]=0;

    printf("enter the starting vertex :");
    scanf("%d",&s);
    printf("shortest path is :");
    dfs(s);

    while(1)
    {

        for(i=0;i<n;i++)
        {
            if(visited[i]!=1)
                break;

        }
        if(i==n)
            break;
        else
        {
            c++;
            dfs(i);

        }
    }
    printf("\nnumber of component is :%d",c);
    printf("\ndegree of vertices are :\n");
    for(i=0;i<n;i++)
    {
        l=0;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
                l++;
        }
        printf("\ndegree of vertex %c is %d",i+65,l);
    }
}

void dfs(int i)
{
    int j;
    printf("%c",(i+65));
    visited[i]=1;
    for(j=0;j<n;j++)
       if(!visited[j]&&a[i][j]==1)
            dfs(j);
}
