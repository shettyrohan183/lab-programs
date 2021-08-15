#include<stdio.h>
#include<conio.h>
    int v,n,i,j,visited[20],q[20],a[20][20],r=-1,f=0;

void bfs(int v)
{
    for(i=1;i<=n;i++)
      if(a[v][i] && !visited[i])
          q[++r]=i;
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}


void main()
{
    printf("enter the number of vertices :");
    scanf("%d",&n);-
    printf("enter the adjacent matrix \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
          scanf("%d",&a[i][j]);

    printf("enter the source vertex :");
    scanf("%d",&v);

    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        q[i]=0;
    }

    bfs(v);
      for(i=1;i<=n;i++)
      {
          if(visited[i])
          printf("%d node is reachable\n",i);
          else
          printf("%d node is not reachable\n",i);
      }

}