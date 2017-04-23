#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queue
{
	int info;
	struct queue *next;
};
typedef struct queue *QUEUE;
void enqueue(QUEUE*,int);
void dequeue(QUEUE*);
int main()
{
	int c,x,pos,coun,lis;
	struct queue *start;//*list1,*list2;
    start=NULL;
	do{
		printf("\n*************************\n"); 
		printf("\n1.ENQUEUE.");
		printf("\n2.DEQUEUE");
		printf("\n\n0.EXIT.");
		printf("\n*************************\n");
		printf("\nEnter choice : ");
		scanf("%d",&c);
		switch(c){
			case 0:printf("\nTHANKYOU FOR PROGRAMMING WITH US.");
			       break;
			case 1:printf("\nEnter value to be Enqueued : ");
			       scanf("%d",&x);
			       fflush(stdin);
			       enqueue(&start,x);
			       break;
			case 2:dequeue(&start);
                   break;
			default:printf("\nWrong Choice\n");
		}
		
	}while(c!=0);
	return 0;
}
void enqueue(QUEUE *plist,int x)
{
	 QUEUE n;
     n=malloc(sizeof(struct queue));
     if(n==NULL)
	 {
         printf("\nQUEUE Overflow.");
         return;
     }
     n->info=x;
     if(*plist==NULL)
     {
          *plist=n;
          n->next=n;
          printf("%d Enqueued.",x);
          return;
     }
     n->next=(*plist)->next;
     (*plist)->next=n;
     *plist=n;
     printf("%d Enqueued.",x);
}
void dequeue(QUEUE *plist)
{
     QUEUE t;
     if(*plist == NULL )
     {
               printf("\nQUEUE Underflow.");
               return;
     }
     if((*plist)->next==*plist)
     {
        t=*plist;
       *plist=NULL;
       printf("\n%d Dequeued.",t->info);
       free(t);
       return;
     }
     t=(*plist)->next;
     (*plist)->next=t->next;
     printf("\n%d Dequeued.",t->info);
     free(t);
}
