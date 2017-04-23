#include<stdio.h>

#define MAXSTACK 30
#define TRUE 1
#define FALSE 0

struct stack/* Declare a structure 'stack' */
{
       int top;
       int items[MAXSTACK];
};
typedef struct stack stk;
void initStack(stk*);/* function prototype for initStack; initialises the stack to empty state */
void push(stk*,int);/* function prototype for push */
void pop(stk*,int*,int*);/*function prototype for pop */
int isOper(char);

int main(void)
{
    stk s;
    char input[MAXSTACK];
    int underflow=FALSE;
    char popped;
    initStack(&s);
    int i,j,oper1,n1,n2;
    int n3=0;
    char temp;
    printf("\nEnter the Postfix Expression.\n");  //
    scanf("%s",input);
    for(i=0;input[i]!='\0';i++)
    {
       if(isOper(input[i])==FALSE)
       {
          oper1=input[i] - '0';
          push(&s,oper1);
       }
       else
       {
           pop(&s,&underflow,&n1);
           pop(&s,&underflow,&n2);
           switch(input[i])
           {
             case '+':n3=n1+n2;
                      push(&s,n3);
                      break;
             case '-':n3=n2-n1;
                      push(&s,n3);
                      break;
             case '*':n3=n1*n2;
                      push(&s,n3);
                      break;
             case '/':n3=n2/n1;
                      push(&s,n3);
                      break;
             case '^':n3=pow(n2,n1);
                      push(&s,n3);
                      break;
           }
       }
    }
    pop(&s,&underflow,&n1);
    printf("The result of the expression is %d",n3);
    getch();
    return 0;
}
int isOper(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
     return TRUE;
    return FALSE;
}
void initStack(stk *ps)/* function definition for initStack */
{
     ps->top=-1;
}
void push(stk *ps,int elem)/* function definition for push */
{
    ps->top=(ps->top)+1;
    ps->items[ps->top]=elem;
}
void pop(stk *ps,int* undercover,int* popped)/* function definition for pop */
{
     if(ps->top==-1)
       *undercover=TRUE;
     else
     {
         *popped=ps->items[(ps->top)--];
          *undercover=FALSE;
     }
}
        
