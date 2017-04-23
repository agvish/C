#include<stdio.h>
#include<conio.h>
int binRecurSrch(int*,int,int,int);
int main(void)
{
    int size,l,h,k,i,result;
    result=0;
    printf("\nEnter the size of array : ");
    scanf("%d",&size);
    int *arr;
    arr=malloc(sizeof(int) * size);
    printf("\nEnter the %d elements of array in sorted order.",size);
    for(i=0;i<size;i++)
     scanf("%d",&arr[i]);
    printf("\nEnter the element to be searched.");
    scanf("%d",&k);
    l=0;
    h=size-1;
    result=binRecurSrch(arr,l,h,k);
    if(result==-1)
     printf("\nElement not found.");
    else
    {
        result+=1;
        printf("Element found at position %d.",result);
    }
    getch();
    return 0;
}
int binRecurSrch(int *a,int low,int high,int key)
{
    int m;
    m=(low+high)/2;
    if(low>high)
     return -1;
    if(a[m]==key)
     return m;
    else if(a[m]>key)
     return binRecurSrch(a,low,m-1,key);
    else
     return binRecurSrch(a,m+1,high,key);
}
