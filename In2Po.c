/*Infix to Postfix Conversion*/
/*Vishal Agarwal*/

#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#define MAXSTACK 30
#define TRUE 1
#define FALSE 0
struct Stack /*Structure definition for stack*/
{
	char items[MAXSTACK];
	int top;
};
typedef struct Stack ST;
void initStack(ST*); /*function prototype for initializing stack*/
void push(ST*,char); /*function prototype for pushing in stack*/
char pop(ST*);       /*function prototype for popping from stack*/
int isPrece(char);   /*function prototype for defining operator precedence*/
int isOper(char);    /*function prototype for validating an operator*/
int main(void)       /*Main Function*/
{
	ST s;            /*variable for stack*/
	initStack(&s);   /*Initializing stack*/
	int i,j;
	char temp;       /*Temporary variable to hold popped character*/
	char input[MAXSTACK]="";
	char output[MAXSTACK]="";
	j=0;
	printf("\nEnter the Infix Operation:\n");
    gets(input);   /*Infix Expression input*/
	for(i=0;input[i]!='\0';i++)
	{
		if(input[i]=='(')  /*Pushing the opening parenthesis*/
		 push(&s,input[i]);
		 
		if(isOper(input[i])==FALSE && input[i]!='(' && input[i]!=')') /*copying of operand on output screen*/
		 {output[j]=input[i];j+=1;}
		 
		if(isOper(input[i])==TRUE && input[i]!='(' && input[i]!=')')  /*Checking for operator*/
		{
			temp=pop(&s);
			if(temp=='(')  /*check for first operator in stack*/
			{
			  push(&s,temp); 
			  push(&s,input[i]);  /*Pushing the first operator*/
			}
			else
			{
				if(temp=='^' && input[i]=='^')  /*check for right associative operator*/
				  push(&s,temp);
			    else
				{
				  while(isPrece(temp)>=isPrece(input[i]))  /*Popping all operator whose precedence is less than incoming operator*/
				  {
					output[j++]=temp;
					temp=pop(&s);
				  }
				  if(isPrece(temp)<isPrece(input[i]))
				   push(&s,temp);
			    }
				push(&s,input[i]); /*Pushing incomig operator*/
				
			}
		}
		if(input[i]==')')  /*Will pop all operator until '(' is encountered*/
		{
			temp=pop(&s);
			printf("\n%c",temp);
			for(;temp!='(';temp=pop(&s))
			{
				output[j]=temp;
				j+=1;
			}
		}
	}
	temp=pop(&s);  /*will pop & append all operator from stack if the incoming list is exhausted*/
	while(temp!='\0')
	{
		output[j]=temp;
		j+=1;
		temp=pop(&s);
	}
	output[j]='\0';
	printf("\nInfix Expression is:\n\n"); /*Displays Infix Expression*/
	puts(input);
	printf("\nPostfix Expression is:\n\n"); /*Displays Postfix Expression*/
	puts(output);

	getch();
	return 0;
}
void initStack(ST *s)
{
	s->top=(-1);  //Initializes top to -1
}
void push(ST *s,char c) /*Function definition for PUSH operation*/
{
	s->top=s->top+1;  
	s->items[s->top]=c;
}
char pop(ST *s)  /*Function definition for POP operation*/
{
	char c;
	if(s->top==-1)
	 return ('\0');
	else
	{
		c=s->items[s->top];
		s->top=s->top-1;
		return c;
	}
}
int isOper(char op) /*Function definition defining Operators*/
{
	if(op=='+'||op=='-'||op=='*'||op=='/'||op=='^')
	{
	 return TRUE;
    }
	return FALSE;
}
int isPrece(char op) /*Function definition for defining operator precedence*/
{
	if(op=='+'||op=='-')
	 return 4;
	if(op=='*'||op=='/')
	 return 6;
	if(op=='^')
	 return 8;
}
