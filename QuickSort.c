/*Program to sort elements by using Quick Sort Alogorithm (Lomuto Partiton).*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sortQuick(int*,int,int);						/*function prototype to perform Quick Sort*/
void displayArray(int*,int);						/*function prototype to display array*/
int lomutoPart(int*,int,int);						/*function prototype to find pivot position using Lomuto Partition*/
int main()
{
	int *arr;
	int i,num,size;
	printf("\nEnter the size of array .  :  ");
	scanf("%d",&size);

	arr = malloc(sizeof(int) * size);				/*Memory allocation for array*/
	srand(time(NULL));
	for(i = 0; i < size; i++)
	{
		num = (rand()%1000) + 1;
		arr[i] = num;						/*Storing random numbers in array.*/
	}
	printf("\nThe elements of array are. : ");
 	displayArray(arr,size);						/*Function call to display original array*/

	sortQuick(arr,0,(size - 1));					/*Function call to sort the array*/

	printf("\nThe elements of array after Sorting are. ");
	displayArray(arr,size);						/*Function call to display sorted array*/

	printf("\n");
	return 0;
}
void sortQuick(int *arr ,int low, int high)				/*Function definition to perform quick sort*/
{
	int pivot;
	if(low < high)
	{
		pivot = lomutoPart(arr ,low,high);			/*Function call to calculate pivot position using Lomuto Partition*/
		sortQuick(arr,low,pivot - 1);
		sortQuick(arr,pivot+1,high);
	}
}
int lomutoPart(int *arr ,int low ,int high)				/*Function definition to calculate pivot position using Lomuto Partition*/
{
	int pivot,i,lastSmall,temp;
	pivot = arr[low];						/*Pivot is the element at position 'low' of partitioned array.*/
	lastSmall = low;						/* first element is considered to be pivot */ 
	for(i = low+1 ; i <= high ; i++)
	{
		if(arr[i] < pivot)
		{
			++lastSmall;					/* Move large entry to right and small to left */  
			temp = arr[i];
			arr[i] = arr[lastSmall];
			arr[lastSmall] = temp;
		}
	}

	/*Put pivot element in correct position*/

	arr[low] = arr[lastSmall];
	arr[lastSmall] = pivot;
	return lastSmall;
}
void displayArray(int *arr, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ",arr[i]);					/*displaying content of array*/
}			
