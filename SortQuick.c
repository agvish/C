/*Program to implement Quick Sort*/

#include<stdio.h>
#include<stdlib.h>
void sortQuick(int*,int,int);											/*function prototype to perform Quick Sort*/
int pivotPos(int*,int,int);												/*function prototype to find pivot position*/
void dispArray(int*,int);													/*function prototype to display array*/
int main()
{
    int size,i;
    int *arr;
    printf("\nEnter the size of array : ");
    scanf("%d",&size);
    arr = malloc(sizeof(int) * size);										/*allocating size for array*/
    
	printf("\nEnter %d element of array.\n",size);
    for(i = 0; i < size; i++)
     scanf("%d",&arr[i]);
    
	sortQuick(arr,0,size);												/*function call to sort the array*/
    
	printf("\nElement of array after sorting is : \n");
	dispArray(arr,size);												/*function call to display sorted array*/
    getch();
    return 0;
}
void sortQuick(int *a,int low,int high)									/*function definition to perform quick sort*/
{
     int pivot;
     if(low < high)
     {
        pivot = pivotPos(a,low,high);										/*function call to calculate pivot position of element in array*/
        sortQuick(a,low,pivot-1);
        sortQuick(a,pivot+1,high);
     }
}
int pivotPos(int *a,int low,int high)									/*function definition to calculate pivot position*/
{ 
    int pivot,i,temp;
	int lastSmall; 														/* position of the last key less than pivot */    
	pivot = a[low]; 													/* first element is considered to be pivot */ 
	lastSmall = low;
	for (i = low + 1; i <= high; i++)
	{
		if (a[i] < pivot)   
		{  
			lastSmall = lastSmall + 1;   								 /* Move large entry to right and small to left */  
			temp = a[i];   
			a[i ] = a[lastSmall];  
			a[lastSmall] = temp;  
		}
	}
	
	/*Put pivot element in correct position*/
	a[low] = a[lastSmall];
	a[lastSmall] = pivot;
  	return lastSmall;  
}
void dispArray(int *a,int size)
{
	int i;
	for(i = 0; i< size; i++)
		printf("%d  ",a[i]);
}
