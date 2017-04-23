/* QUEUE (array to hold elements of the queue) */
#include<stdio.h>

#define MAXQUEUE 4
#define TRUE 1
#define FALSE 0

struct queue/* Declare a structure 'queue' */
{
       int front,rear;
       int items[MAXQUEUE];
};
typedef struct queue Q;
int empty(Q*);/* function prototype for empty; returns TRUE if queue is empty, FALSE otherwise */
void initQueue(Q*);/* function prototype for initQueue; initialises the queue to empty state */
void append(Q*,int*,int);/* function prototype for append */
void serve(Q*,int*,int*);/*function prototype for serve */

int main(void)
{
    Q q;
    int x,served,oflow,uflow,choice;/* define necessary variables */
	initQueue(&q);/*function call to initStack */
	oflow=uflow=TRUE;
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
					append(&q,&oflow,x);/* function call to Append */
					if(oflow==1)/*DoIt: check for overflow*/
					   printf("\nQueue Overflow.\n");
					else
					   printf("\n%d was appended successfully to Queue.\n",x);
					break;
			case 2: serve(&q,&uflow,&served);/* function call to serve */
					if(uflow==1)/*DoIt: check for underflow*/
					   printf ("\nQueue Underflow.\n");
					else
					   printf("\nDeleted element is %d.\n",served);
					break;
			case 3: break;
			default:	printf("\nInvalid choice. Try again.\n");
		}
	}while(choice!=3);
	return 0;
}/* end of main */

int empty(Q *qs)/* function definition for empty */
{
    if(qs->front==qs->rear)
     return TRUE;
    else
     return FALSE;
}
void initQueue(Q *qs)/* function definition for initQueue */
{
     qs->front=-1;
     qs->rear=-1;
}
void append(Q *qs,int* o,int elem)/* function definition for append */
{
    if(qs->rear==(MAXQUEUE-1))
     *o=TRUE;
    else
    {
     qs->rear=(qs->rear)+1;
     qs->items[qs->rear]=elem;
     *o=FALSE;
    }
}
void serve(Q *qs,int* u,int* elem)/* function definition for serve */
{
    if(empty(qs)==1)
    {
      *u=TRUE;
      initQueue(qs);
    }
     else
     {
      *elem=qs->items[++(qs->front)];
      *u=FALSE;
     }
}
