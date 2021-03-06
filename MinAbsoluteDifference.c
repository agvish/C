/*The following code calculates minimum absolute difference between any two elements in an array*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n,i,diff,absdiff;
    diff=0;                                                                   //Initially the difference is set to 0
    absdiff=INT_MAX;                                                          //Absolute diiference is initailly set to largest positive value that an 'int' can hold
    printf("\nEnter the number of elements you want to input : ");
    scanf("%d",&n);
    int *arr = malloc(sizeof(int) * n);                                       //Creation of memory blocks for array
    for(i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
    }
    for(i = 0; i < n-1; i++)                                                  //iterates (n-1) times
    {
       for(j = i+1; j < n; j++)
        {
            diff = abs(a[i] - a[j]);                                          //calculates absolute difference between ith and jth element
            if(diff < absdiff)                                                //checks whether it is less than minimum absolute difference
               absdiff = diff;
        }
    }
    printf("Minimum Absolute difference between any two elements in given aaray is %d",absdiff);
    return 0;
}
\
