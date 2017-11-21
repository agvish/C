/*Program to sort elements by using Merge Sort Alogorithm.*/


#include<stdio.h>
#include<stdlib.h>
void mergeSort(int*, int, int);				 //Function prototype to sort array using Merge Sort
void merge(int*, int, int, int);			//Function prototype to merge two arrays
int main()
{

	int *arr;
	int i,size,compare;
	printf("\nEnter the size of array : ");
	scanf("%d",&size);
	arr = malloc(sizeof(int) * size);		//Memory allocation to store elements

	srand(time(NULL));

	for(i = 0; i < size; i++)
		arr[i] = (rand()%1000) + 1;		//Storing random numbers in array

	printf("\nOriginal Array is : \n");
	for(i = 0 ; i < size ; i++)
		printf("%d ",arr[i]);

	mergeSort(arr, 0 ,(size - 1));			//Function call to sort randomly generated data using Merge Sort
	
	printf("\n\nSorted Array is : \n");
	for(i = 0 ; i < size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
void mergeSort(int *arr, int start, int end)		//Function definition to sort array using Merge Sort
{
	int mid;
	if(start < end)
	{
		mid = start + (end - start)/2 ;		//Calculating the mid position.
		mergeSort(arr, start, mid);		//Dividing array from start to mid position recursively
		mergeSort(arr, mid+1, end);		//Dividing array from mid to end position recursively
		merge(arr, start, mid, end);		//Function call to merge two arrays
	}
}
void merge(int *arr, int start, int mid, int end)	//Function call to merge two arrays
{
	int *aux;
	int x,y,i,j,k;

	x = (mid - start) + 1;				//Calculating the size of first half of original array
	aux = malloc(sizeof(int) * x);			//Memory allocation to store elements of first half of original array

	for( i = start , j = 0; i <= mid; j++,i++)
		aux[j] = arr[i];			//Copying element of first half of original array to auxilliary array

	/*Variable 'i' is the end position of auxilliary array or the starting position of second half of original array*/

	y = 0;
	k = start;
	while((k < i) && (i <= end))			//Loop to merge elements of auxilliary array and elements in second half of original array
	{
		if(aux[y] <= arr[i])			//if the element in auxiliary array is less than elements in second half of original array
			arr[k++] = aux[y++];		//Copying the element of auxilliary array to original array
		else 					//if the element in auxiliary array is greater than elements in second half of original array
			arr[k++] = arr[i++];		//Copying the element of second half of array to original array
	}
	while(k < i)					//If the second half of array has exhausted, copy the remaining element of auxilliary array to original array
	{
		arr[k++] = aux[y++];
	}
}
