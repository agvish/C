/* Linear Search */
#include<stdio.h>

#define MAX 10
int linearSearch(int [],int,int);	/* 	arguments are array to hold the elements, no. of elements in the array, key element to search for
                                        returns -1 if the element is not found
										returns the position of the element, if it is found */
int main(void)
{
	int a[MAX];
	int i,n,key,pos;	/* pos will hold the return value from linearSearch */
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	
	printf("Enter the elements:\n");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	
	printf("Enter the key value to search for:\n");
	scanf("%d",&key);
	
	pos=linearSearch(a,key,n);/*function call to linearSearch*/
	
	if (pos == -1)
		printf("Search for the key %d failed.\n",key);
	else
		printf("Key %d was found in position %d.\n", key, pos);
	getch();	
	return 0;
}/*end of main*/

int linearSearch(int a[],int key,int n)/* function definition of linearSearch */
{
    int i=0;
    for(i=0;i<n;i++)
    {
      if(a[i]==key)
       return i+1;
    }
    return i;
}
