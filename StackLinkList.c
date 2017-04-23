#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack
{
	int info;
	struct stack *next;
};
typedef struct stack *STACK;
void push(STACK*,int);
void pop(STACK*);
int main()
{
	int c,x,pos,coun,lis;
	struct stack *start;//*list1,*list2;
    start=NULL;
	do{
		printf("\n*************************\n"); 
		printf("\n1.PUSH.");
		printf("\n2.POP");
		printf("\n\n0.EXIT.");
		printf("\n*************************\n");
		printf("\nEnter choice : ");
		scanf("%d",&c);
		switch(c){
			case 0:printf("\nTHANKYOU FOR PROGRAMMING WITH US.");
			       break;
			case 1:printf("\nEnter value to be pushed : ");
			       scanf("%d",&x);
			       fflush(stdin);
			       push(&start,x);
			       break;
			case 2:pop(&start);
                   break;
			default:printf("\nWrong Choice\n");
		}
		
	}while(c!=0);
	return 0;
}
void push(STACK *plist,int x)
{
	STACK n;
	n=(STACK)malloc(sizeof(struct stack));
	if(n==NULL)
	{
         printf("\nStack Overflow.");
         return;
    }
	n->info=x;
	n->next=*plist;
	*plist=n;
	printf("%d was Pushed.",x);
}
void pop(STACK *plist)
{
     if(*plist == NULL)
     {
               printf("\nStack Underflow.");
               return;
     }
     STACK t;
     t=*plist;
     *plist=t->next;
     printf("\n%d Popped.",t->info);
     free(t);
}
