/*Program that will search for a key in a given set of input as an array. The searching algorithm used here is recursive binary search*/


#include<stdio.h>
#include<conio.h>
int binRecurSrch(int*,int,int,int);         /*function prototype for the recursive binary search*/
int main(void)
{
    /*Variable to store size, lower bound, upper bound of array, result of search. */
    
    int size,l,h,k,i,result;
    
    /*A pointer variable to declare 1-d array dynamically*/
  
    int *arr;
    result=0;
    printf("\nEnter the size of array : ");
    scanf("%d",&size);
    arr=malloc(sizeof(int) * size);
    printf("\nEnter the %d elements of array in sorted order.",size);
    for(i=0;i<size;i++)
     scanf("%d",&arr[i]);
    printf("\nEnter the element to be searched.");
    scanf("%d",&k);
    /*Assigning the value of lower bound and the upper bound*/
    l=0;
    h=size-1;
    result=binRecurSrch(arr,l,h,k);               //call to recursive binary search function
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

/*Definition of binary search recursive function*/
int binRecurSrch(int *a,int low,int high,int key)
{
    int m;
    m=(low+high)/2;  /*Calculating the middle position of array*/
    if(low>high)    /*Base case*/
     return -1;
    if(a[m]==key)    /*Key element found at middle position*/
     return m;
    else if(a[m]>key)    /*Key element value is less than that of the value at middle position*/
     return binRecurSrch(a,low,m-1,key);           /*Decreasing the upper bound*/
    else                /*Key element value is greater than that of the value at middle position*/
     return binRecurSrch(a,m+1,high,key);           /*Increasing the lower bound*/
}
