/* Binary Search (non-recursive) */
/* As a pre requisite of binary search we have assumed that the input is already sorted*/
#include<stdio.h>

#define MAX 10
int binarySearch(int [],int,int);	/* 	arguments are array to hold the elements, no. of elements in the array, key element to search for
                                        returns -1 if the element is not found
										returns the position of the element, if it is found */
int main(void)
{
	int a[MAX];
	int i,n,key,pos;	/* pos will hold the return value from binarySearch */
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	
	printf("Enter the elements:\n");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	
	printf("\nEnter the key value to search for:\n");
	scanf("%d",&key);
	
	pos=binarySearch(a,key,n);/* function call to binarySearch*/
	
	if (pos == -1)
		printf("Search for the key %d failed.\n",key);
	else
		printf("Key %d was found in position %d.\n", key, pos);
	getch();	
	return 0;
}/*end of main*/

int binarySearch(int a[],int k,int n)/* function definition of binarySearch */
{
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(a[mid]==k)
         return mid+1;
        else if(a[mid]>k)
         high=mid-1;
        else
         low=mid+1;
    }
    return -1;
}
