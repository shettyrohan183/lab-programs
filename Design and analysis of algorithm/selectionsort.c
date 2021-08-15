#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
for(i=0;i<n-1;i++)
{
    min=i;
    for(j=i+1;j<n;j++)
    {
if(a[j]<a[min])
{
    min=j;
}

    }
temp=a[min];
a[min]=a[i];
a[i]=temp;

}
end=clock();
printf("the sorted elemets are\n");
for(i=0;i<n;i++)
{
    printf("%d\t",a[i]);
}
totaltime=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nthe total time taken is %e ",totaltime);
return 0;
}


