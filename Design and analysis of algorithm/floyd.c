#include<stdio.h>
#include<conio.h>
#include<math.h>
void floyd(int p[10][10],int n) {
	int i,j,k;
	for (k=1;k<=n;k++)
{
	  for (i=1;i<=n;i++)
{
	   for (j=1;j<=n;j++)
{
if(p[i][j]>p[i][k]+p[k][j])
	    p[i][j]=p[i][k]+p[k][j];

}
}
printf("the transitive closure  matrix formed at k=%d is\n", k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",p[i][j]);
        printf("\n");
    }
}
}




void main()
{
    int p[10][10]={
        1000}
        ,n,e,i,j,u,v,w;

    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the number of edges\n");
    scanf("%d",&e);
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            p[i][j]=0;
            else
            p[i][j]=10000;
        }
    }
    for(i=1;i<=e;i++)
    {
    printf("enter end vertices of the edge %d from starting to end of arrow\n",i);
    scanf("%d%d",&u,&v);
    printf("enter the value of the %d edge \n",i);
    scanf("%d",&w);
    p[u][v]=w;
     }
    printf("the intial  matrix formed is\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",p[i][j]);
        printf("\n");
    }
    floyd(p,n);
    
getch();
}