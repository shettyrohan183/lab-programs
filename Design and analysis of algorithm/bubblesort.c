#include<stdio.h>
#include<conio.h>
#include<time.h>
int main()
{
    
    int n,i,j,temp;
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
        for(j=0;j<n-1-i;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    end=clock();

    printf("the bubble sorted elemets are\n");
for(i=0;i<n;i++)
{
    printf("%d\t",a[i]);
}
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\ntime taken is %e",totaltime);
    
return 0;
}