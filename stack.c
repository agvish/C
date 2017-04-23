/* STACK (array to hold elements of the stack) */
#include<stdio.h>

#define MAXSTACK 4
#define TRUE 1
#define FALSE 0

struct stack/* Declare a structure 'stack' */
{
       int top;
       int items[MAXSTACK];
};
typedef struct stack stk;
int empty(stk*);/* function prototype for empty; returns TRUE if stack is empty, FALSE otherwise */
void initStack(stk*);/* function prototype for initStack; initialises the stack to empty state */
int push(stk*,int);/* function prototype for push */
int pop(stk*);/*function prototype for pop */

int main(void)
{
	stk s;int x,popped,choice,flag;/* define necessary variables */
	initStack(&s);/*function call to initStack */
	do
	{
		printf("\n----------- MENU -------------\n");
        printf("\n 1. PUSH    2. POP    3. EXIT\n");
        printf("\n------------------------------\n");
        printf("\nEnter your choice (1 / 2 / 3): ");
        scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the element to push: ");
					scanf("%d",&x);
					flag=push(&s,x);/* function call to push */
					if(flag==1)/*DoIt: check for overflow*/
					   printf("\nStack Overflow.\n");
					else
					   printf("\n%d was pushed successfully to stack.\n",x);
					break;
			case 2: popped=pop(&s);/* function call to pop */
					if(popped==1)/*DoIt: check for underflow*/
					   printf ("\nStack Underflow.\n");
					else
					   printf("\nPopped element is %d.\n",popped);
					break;
			case 3: break;
			default:	printf("\nInvalid choice. Try again.\n");
		}
	}while(choice!=3);
	return 0;
}/* end of main */

int empty(stk *ps)/* function definition for empty */
{
    if(ps->top==-1)
     return TRUE;
    else
     return FALSE;
}
void initStack(stk *ps)/* function definition for initStack */
{
     ps->top=-1;
     ps->items[MAXSTACK]=0;
}
int push(stk *ps,int elem)/* function definition for push */
{
    if(ps->top==(MAXSTACK-1))
     return TRUE;
    ps->top=(ps->top)+1;
    ps->items[ps->top]=elem;
    return FALSE;
}
int pop(stk *ps)/* function definition for pop */
{
    int x;
    if(empty(ps)==1)
     return TRUE;
    x=ps->items[(ps->top)--];
    //ps->top=(ps->top)-1;
    return x;
}




