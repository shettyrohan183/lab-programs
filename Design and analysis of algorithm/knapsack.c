#include<stdio.h>
int max(int a,int b){
    if(a>b)
        return a;
        else
        return b;
}
int knapsack(int m,int n,int w[],int p[])
{
    int knap[n+1][m+1],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
        {
            knap[i][j]=0;
        }
        else if(j-w[i]<0)
        {
            knap[i][j]=knap[i-1][j];
        }
        else
        {
            knap[i][j]=max(knap[i-1][j],p[i]+knap[i-1][j-w[i]]);
        }
        }
    }
    printf("the knapsack values are \n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d\t",knap[i][j]);
        }
        printf("\n");
    }
    return knap[n][m];
    
}
int main()
{
    int n=0,m=0,i=0;
    printf("enter the number of objects\n");
    scanf("%d",&n);
     printf("enter the capacity of kanpsack\n");
    scanf("%d",&m);
    int w[n],p[n];
    for(i=1;i<=n;i++)
    {
    printf("enter the weight of %d objects\n",i);
     scanf("%d",&w[i]);
     printf("enter the profit of %d objects\n",i);
    scanf("%d",&p[i]);
    } 

printf("the max solution is %d",knapsack(m,n,w,p));
}