#include<stdio.h>
#include<stdio.h>
#include<time.h>
 void sort(int a[],int lb,int ub)
{
    int s=0;
    if(lb<ub)
    {
        s=partition(a,lb,ub);
        sort(a,lb,s-1);
        sort(a,s+1,ub);
    }
}
int partition(int a[],int lb,int ub)
{
    int p=0,i=0,j=0,temp=0;
    p=a[lb];
    i=lb;
    j=ub;
    while(i<j)
    {
while(a[i]<=p && i<ub)
i++;
while(a[j]>p)
j--;
if(i<j)
{
    temp=a[j];
    a[j]=a[i];
    a[i]=temp;
}
    }
    temp=a[lb];
    a[lb]=a[j];
    a[j]=temp;

return j;
}
int main()
{
    int n,i,min,j,temp;
    clock_t start,end;
    double totaltime;
    

    printf("enter the number of elements in the array :");
    scanf("%d",&n);
int a[n];
    
    for(i=0;i<n;i++)
{
    printf("enter the %d elements of the array\n",i+1);
    scanf("%d",&a[i]);
}
start=clock();
sort(a,0,n-1);
end=clock();
printf("the sorted array is \n");
for(i=0;i<n;i++)
{
    printf("%d\t",a[i]);
}
totaltime=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nthe total time taken is %e ",totaltime);
return 0;
}