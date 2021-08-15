#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void merge(int arr[],int lb,int mid,int ub);



 void sort(int arr[], int lb, int ub)
{
    int mid=0;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;   
    sort(arr, lb, mid);
    sort(arr, mid + 1, ub);
    merge(arr, lb, mid, ub);
    }
       
}
void merge(int arr[], int lb, int mid, int ub)
{
    int i = 0, j =0, k = 0;
    int n1=mid-lb+1,n2=ub-mid;
    int l[n1],r[n2];
    for(i=lb,j=0;i<=mid;i++,j++)
    l[j]=arr[i];
    for(i=mid+1,j=0;i<=ub;i++,j++)\
    r[j]=arr[i];

    i=0,j=0,k=lb;
    while (i < n1 && j < n2)
    {
        if (l[i] < r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (j < n2)
    {
        arr[k] = r[j];
        k++;
        j++;
    }

    while (i < n1 )
    {
        
        arr[k] = l[i];
        k++;
        i++;
    }

}

int main()
{
    int n=0;
    int  i=0;
      clock_t start,end;
     double totaltime;
    printf("enter the number of elements in the array  of mergesort:");
    scanf("%d", &n);
    int a[n];
    
    for (i = 0; i < n; i++)
    {
        printf("enter the %d elements of the array\n", i+1);
        scanf("%d", &a[i]);
    }
    start=clock();
    sort(a, 0, n-1);
    end=clock();
        printf("the sortted array is\n");
        for (i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nthe total time taken is %e ",totaltime);
return 0;
 

}