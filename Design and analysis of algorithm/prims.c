#include<stdio.h>
#include<conio.h>
int n;
int prim(int n,int cost[n][n])
{
    int temp=0,i=0,j=0,startv=0,endv=0,tree[n][3],mincost=0,nrv[n],k=0;
    temp=cost[0][0];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            if(cost[i][j]<temp)
            {
                temp=cost[i][j];
                startv=i;
                endv=j;
            }
        }
    }
tree[0][0]=startv;
tree[0][1]=endv;
tree[0][2]=temp;
mincost=temp;
for(i=-0;i<n;i++){
    if(cost[i][startv]<cost[i][endv])
    {
        nrv[i]=startv;
    }
    else
    nrv[i]=endv;
}
nrv[startv]=100;
nrv[endv]=100;

//finding minimum spanning tree for remaining n-1 vertex
temp=99;
for(i=1;i<n-1;i++)
{
    for(j=0;j<n;j++)
    {
        if(nrv[j]!=100 && cost[j][nrv[j]]<temp)
        {
            temp=cost[j][nrv[j]];
            k=j;
        }
    }
    tree[i][0]=k;
    tree[i][1]=nrv[k];
    tree[i][2]=cost[k][nrv[k]];
    mincost=mincost+cost[k][nrv[k]];
    nrv[k]=100;



   //updating the nextreachable vertex(nrv)
   for(j=0;j<n;j++)
   {
       if(nrv[j]!=100 && cost[j][nrv[j]]>cost[j][k])
       nrv[j]=k;
   }

   temp=99;
}

printf("the minimum spanning tree\n");
printf("from\tto\tvalue\n");
for(i=0;i<n-1;i++)
{
    for(j=0;j<3;j++)
    {
        printf("%d\t",tree[i][j]);
    }
    printf("\n");
}

printf("the mincost is %d\n",mincost);
return 0;
}


int main()
{
    int i=0,j=0;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    int cost[n][n];
        printf("enter the cost of the vertices in matrix form\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }   
     printf("the cost matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }
prim(n,cost);
}