/* Program to implement a Circular Queue where an integer value is used to count the entries in queue. It will increase by one for every append operation
   and decrease by one for every serve opertion.*/
#include<stdio.h>

#define MAXQUEUE 4
#define TRUE 1
#define FALSE 0

struct cqueue                                      			/* Declare a structure 'queue' */
{
       int front,rear;
       int items[MAXQUEUE];
};
typedef struct cqueue CQ;
int empty(CQ*);                                            /* function prototype for empty; returns TRUE if queue is empty, FALSE otherwise */
void initCQueue(CQ*,int*);                             	   /* function prototype for initQueue; initialises the queue to empty state */
void appendCir(CQ*,int,int*);                     		   /* function prototype for appending an element into Queue */
void serveCir(CQ*,int*);                     			   /*function prototype for serve an element from queue */

int main(void)
{
    CQ cq;
    int x,served,choice,count;                             /* defining variables for appending, serving element, choice input and count entries in queue */
	initCQueue(&cq,&count);                                /*function call to "initStack()" for initializing queue to empty state*/
	do
	{
		printf("\n----------- MENU -------------\n");
        printf("\n 1. APPEND    2. SERVE    3. EXIT\n");
        printf("\n------------------------------\n");
        printf("\nEnter your choice (1 / 2 / 3): ");
        scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the element to append: ");
					scanf("%d",&x);
					appendCir(&cq,x,&count);                /* function call to "appendCir()" for inserting an element into queue */
					break;
			case 2: serveCir(&cq,&count);				    /* function call to "serveCir()" for deleting an element from queue */
					break;
			case 3: printf("\nThank You");
					break;
			default:printf("\nInvalid choice. Try again.\n");
		}
	}while(choice!=3);
	return 0;
}/* end of main */

int empty(CQ *qs)											/* function definition for empty queue */
{
    if(qs->front == qs->rear)
     return TRUE;
    else
     return FALSE;
}
void initCQueue(CQ *qs, int *count)							/* function definition for "initCqueue()" to initialize queue to empty state */
{
     qs->front = 0;
     qs->rear = 0;
     *count = 0;
}
void appendCir(CQ *qs,int elem,int *count)                  /* function definition for inserting an element */
{
     if(*count == MAXQUEUE)									/*if number of element is equal to the length of queue*/
     {
     	printf("\nQueue Overflow");
     	return;
     }
     qs->items[(qs->rear)++] = elem;						/*insert an element at rear*/
     *count = *count+1;										/*Increase the count variable for successful insertion*/
     printf("\nThe element %d was appended to the Queue.",elem);
}
void serveCir(CQ *qs,int* count)							/* function definition for deleting an element */
{
    if(empty(qs)==1)										/*if call to "empty()" function returns a TRUE value*/
    {
    	printf("Queue Underflow.");
        initCQueue(qs,count);								/*Re-initailaizng queue to an initial empty state*/
        return;
    }
    else
    {
      printf("Element served from Queue is : %d",qs->items[(qs->front)++]);    /*Delete an element from front*/
      *count = *count - 1;													   /*Decrease the count variable for successful deletion*/
    }
}
