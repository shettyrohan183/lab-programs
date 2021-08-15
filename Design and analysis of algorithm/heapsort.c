#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>

heapify(int n,int i, int a[])
{
    int largest=i,temp=0;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest])
      largest=l;
    if(r<n && a[r]>a[largest])
       largest=r;
    if(largest!=i)
       {
           temp=a[i];
           a[i]=a[largest];
           a[largest]=temp;
       heapify(n,largest,a);
       }

}
void heapsort(int n,int a[])
{
    int i,temp=0;
    for(i=((n/2)-1);i>=0;i--)
      heapify(n,i,a); 

    for(i=n-1;i>0;i--)
    {
       temp=a[0];
       a[0]=a[i];
       a[i]=temp;
       heapify(i,0,a);
    }
}
void printarray(int n,int a[])
{  
    int i=0;
    for(i=0;i<n;++i)
    {
       printf("%d\t",a[i]);
    }
}
void main()
{
    int n, i = 0;
    clock_t start, end;
    double totaltime;
    printf("enter the number of elements :");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements \n");
    for (i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
    }
    start = clock();
    heapsort(n, a);
    end=clock();
    printarray(n,a);

        totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n\ntime taken is %e\n",totaltime);

    printf("\nthe time taken for larger number of arrays are\n");
int k=0;

int c=0;
while(k<5){
c=c+2000;

end=0;
start=0;
totaltime=0;
int arr[c];
for(i=0;i<c;i++)
{
arr[i]=rand();
}
start=clock();
heapsort(c,arr);
end=clock();
totaltime=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nthe total time taken for %d element is %e\n",c,totaltime);
k++;
}
}