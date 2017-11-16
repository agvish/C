/*Program to implement Fractional Knapsack problem.*/

#include<stdio.h>
#include<stdlib.h>
void knapsack(int,float*,float*,int);								//Function Prototype to calculate which item can fit in Knapsack to give maximu profit
void sort(float*,int,int*);										//Function Prototype to sort item in Non Increasing order(Bubble Sort)
int main()
{
	int i,total,maxsize;										//Varaibles for loop,total number of items and max size of knapsack	
	float *weight,*profit;

	printf("\nEnter the total number of items : ");
	scanf("%d",&total);										//Storing total number of items available

	weight = malloc(sizeof(float) * total);						//Memory allocation to hold 'weight' of each item
	profit = malloc(sizeof(float) * total);						//Memory allocation to hold 'profit' of each item

	printf("\nEnter the Weight of %d items.\n",total);
	for(i = 0 ; i < total ; i++)
		scanf("%f",&weight[i]);								//Storing weight of each item

	printf("\nEnter the Profit of %d items.\n",total);
	for(i = 0 ; i < total ; i++)
		scanf("%f",&profit[i]);								//Storing profit of ach item

	printf("\nEnter the maximum size of KNAPSACK : ");
	scanf("%d",&maxsize);									//Storing the maximum size of Knapsack

	knapsack(total,weight,profit,maxsize);						//function call to calculate which items can fit in Knapsack to give maximum profit
	printf("\n");
	return 0;
}
void knapsack(int total , float *weight , float *profit , int maxsize)
{
	float *profitweight,*soln,fracSize,maxProfit = 0;				/*Variable to store Profit_to_Weight ratio of items, required quantity of each item, fractional size of item and total profit of item in knapsack */
	int *order;											/*Keeps track of correct position of a particular item when they get sorted in Profit_to_weight ratio*/
	int i,currWeight = 0,knapSize = 0;

	order = malloc(sizeof(int) * total);							//Memory allocation to hold the ordering of the items
	soln = malloc(sizeof(int) * total);							//Memory allocation to hold the quantity of item.
	profitweight = malloc(sizeof(float) * total);					//Memory allocation to hold Profit_to_Weight ratio of each item
	
	for(i = 0 ; i < total ; i++)								//Initializing solution array
		soln[i] = 0;
	
	for(i = 0 ; i < total ; i++)
	{
		profitweight[i] = profit[i] / weight[i];					//Storing the Profit_to_Weight ratio of each item
		order[i] = i;										//Storing initial ordering of each item
	}
	
	sort(profitweight,total,order);								//Function call to sort Profit_to_Weight ratio's array in non increasing order and to keep track of ordering of item after sorting

	for(i = 0 ; i < total ; i++)
	{
			currWeight = weight[order[i]];					//Stores the weight of current item
			knapSize += currWeight;							//Adding that complete item to Knapsack
			if(knapSize < maxsize)							//Check if it can fit in Knapsack
			{
				soln[i] = 1;								//Storing the full item in the Knapsack
				maxProfit += profit[order[i]];					//Adding up the profit
			}
			else
			{
				knapSize -= currWeight;						//Removing that complete item from knapsack
				fracSize = (maxsize - knapSize) ;				//Calculating the availabe size on knapsack
				fracSize /= currWeight;						//Calculating the ratio of availabe size in kanpsack to current size of item
				soln[i] = fracSize;							//Storing that fractional size of item
				maxProfit += fracSize * (profit[order[i]]);
				break;									//Halting the process since Knapsack is FULL
			}
	}
	for(i = 0 ; i < total ; i++)
	{
		printf("%.2f of item %d \n",soln[i],order[i]);				//Displaying the solution of problem.
	}
	printf("\nThe Maximum Profit is %.3f . ",maxProfit);				//Displaying the Maximum Profit
}
void sort(float *arr , int n , int *order)							//Function definition to sort array in Non Increasing order.
{
	int i,j;												//Loop variable
	float temp1,temp2;										//Variable used for swapiing two numbers
	for(i = 0; i < n; i++)									//Runs for the total number of items in an array
	{
		for(j = 0 ; j < (n-i-1) ; j++)							//Runs for storing the sorted element to the last of array
		{	
			if(arr[j] < arr[j+1])
			{
				temp1 = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp1;

				temp2 = order[j];
				order[j] = order[j+1];
				order[j+1] =temp2;
			}
		}
	}
}
