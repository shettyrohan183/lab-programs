#include<stdio.h>
#include<conio.h>
                 
void diikstra(int n,int u,int a[n][n])
{
    int i=0,dis[n],pre[n],vis[n],mindis=100,count=0,nextv=0,j=0;
    for(i=0;i<n;i++)
    {
        dis[i]=a[u][i];
        pre[i]=u;
        vis[i]=0;
    }
    dis[u]=0;
    vis[u]=0;
    count=1;
    while(count<n-1)
    {
        mindis=100;
        for(i=0;i<n;i++)
            if(dis[i]<mindis && !vis[i])
            {
                mindis=dis[i];
                nextv=i;
            }
            vis[nextv]=1;
        for(i=0;i<n;i++)
            if(!vis[i])
                if(mindis+a[nextv][i]<dis[i])
                {
                    dis[i]=mindis+a[nextv][i];
                    pre[i]=nextv;
                }
                count++;
    }
    for(i=0;i<n;i++)
    {
        if(i!=u)
        {
            printf("\ndistance of node %d from start node =%d",i,dis[i]);
            printf("\npath=%d",i);
            j=i;
            do
            {
                j=pre[j];
                printf("--%d",j);
            }while(j!=u);
        }
    }
}
int main()
{
    int n,i=0,j=0,s;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    int aj[n][n];
    printf("enter the aiacent matrix(enter 99 for infinity value)\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&aj[i][j]);
        }
    } 
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",aj[i][j]);
        }
        printf("\n");
    }
        printf("enter the starting vertice\n");
        scanf("%d",&s);
        diikstra(n,s,aj);
}