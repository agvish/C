/*Program to implement Single Linked List*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node											/*Structure Definition for a node*/
{
	int info;
	struct node *next;
};
typedef struct node *NODEPTR;
void createList(NODEPTR*);									/*function prototype to create a List*/
void insertBeg(NODEPTR*,int);									/*function prototype to insert a node at begining of list*/
void insertLast(NODEPTR*,int);						 			/*function prototype to insert a node at the end of list*/
void insertPos(NODEPTR*,int,int);								/*function prototype to insert a node at a specified position*/
void insertVal(NODEPTR*,int,int);								/*function prototype to insert  node(s) after a specified node value*/
void deleteBeg(NODEPTR*);									/*function prototype to delete a node at begining of list*/
void deleteLast(NODEPTR*);									/*function prototype to delete a node at end of list */
void deletePos(NODEPTR*,int);									/*function prototype to delete a node at a specified position*/
void deleteVal(NODEPTR*,int);									/*function prototype to delete node(s) with a specified value*/
void revList(NODEPTR*);										/*function prototype to reverse the whole list*/
int count(NODEPTR);										/*function prototype to count the total number of nodes in a list*/
void displayList(NODEPTR);									/*function prototype to display the list*/
int main()
{
	int c,x,pos,coun;							
	struct node *start;									/*external pointer to hold the entire list*/
	start=NULL;										/*Initializing the external pointer to default NULL state*/
	createList(&start);									/*function call to create a list*/
	do{
		printf("\n*************************\n");
		printf("\n1.Insert a Node at the very begining.");
		printf("\n2.Insert a Node at the END.");
		printf("\n3.Insert a Node at specified position.");
		printf("\n4.Insert a Node after a specified node value.");
		printf("\n5.Delete a Node from begining.");
		printf("\n6.Delete a Node from last.");
		printf("\n7.Delete a Node from specified position.");
		printf("\n8.Delete a Node after a specified node value.");
		printf("\n9.Reverse the List.");
		printf("\n10.Display List");
		printf("\n11.Count the number of nodes in a list.");
		printf("\n\n0.EXIT.");
		printf("\n*************************\n");
		printf("\nEnter choice : ");
		scanf("%d",&c);
		switch(c){
			case 0:printf("\nTHANKYOU FOR PROGRAMMING.");
			       break;
			case 1:printf("\nEnter value to be inserted at begining : ");
			       scanf("%d",&x);
			       fflush(stdin);
			       insertBeg(&start,x);						/*function call to insert a node at the begining of list*/
			       break;
			case 2:printf("\nEnter value to be inserted at Last : ");
			       scanf("%d",&x);
			       fflush(stdin);
			       insertLast(&start,x);						/*function call to insert a node at the end of list*/
			       break;
			case 3:printf("\nEnter value to be inserted : ");
			       scanf("%d",&x);
			       printf("\nEnter the specified position : ");
			       scanf("%d",&pos);						/*storing the position at which the node is to be inserted*/
			       fflush(stdin);
			       insertPos(&start,x,pos);						/*function call to insert a node at specified position*/
			       break;
			case 4:printf("\nEnter value to be inserted : ");
			       scanf("%d",&x);
			       printf("\nEnter the value after which %d will be inserted  : ",x);
			       scanf("%d",&pos);						/*storing the value after which node(s) is to be inserted*/
			       fflush(stdin);
			       insertVal(&start,x,pos);						/*function call to insert node(s) after specified value*/
			       break;
			case 5:deleteBeg(&start);						/*function call to delete a node from the begining of list*/
					break;
			case 6: deleteLast(&start);						/*function call to delete a node from the end of list*/
					break;
			case 7: printf("\nEnter the position of node which needs to be delelted  : ");
			       	scanf("%d",&pos);						/*storing the position at which the node is to be deleted*/
			       	fflush(stdin);
			       	deletePos(&start,pos);						/*function call to delete a node at given position*/
					break;
			case 8: printf("\nEnter the value of node which will be deleted  : ");
			       	scanf("%d",&pos);						/*storing the value which is to be deleted*/
			       	fflush(stdin);
			       	deleteVal(&start,pos);						/*function call to delete node(s) with a specified values*/
			       	break;
			case 9: revList(&start);						/*function call to reverse list*/
					break;
			case 10:displayList(start);						/*function call to display the list*/
			       break;
			case 11:coun=count(start);						/*Holds the total number of nodes in a list*/
					printf("\nThere are %d nodes in your List.",coun);
					break;
			default:printf("\nWrong Choice\n");
		}
		
	}while(c!=0);
	return 0;
}

void createList(NODEPTR *plist)									/*function definition to create a List*/
{
	NODEPTR newNode, prevNode;								/*variable to hold new and previous node*/
	int x;
	char ch;
	do{
		printf("\nEnter the value of node : ");
		scanf("%d",&x);
		newNode = malloc(sizeof(struct node));						/*creation of a new node*/
		newNode->next = NULL;
		newNode->info = x;
		if(*plist == NULL)								/*If initially the list is empty*/
			*plist = newNode;							/*External pointer will hold the address of new node*/
		else
			prevNode->next = newNode;						/*previous node will point to the new node */
		
		printf("\n Want to continue ? (Y/y) : ");
		fflush(stdin);									/*flushing the input buffer*/
		scanf("%c",&ch);
		prevNode = newNode;								/*current node becomes the previous node of the list*/
	}while(ch == 'y' || ch == 'Y');
}
void insertBeg(NODEPTR *plist,int x)								/*function definition to insert a node at begining of list*/
{
	NODEPTR newNode;
	newNode = (NODEPTR)malloc(sizeof(struct node));						/*creation of a new node*/
	newNode->info = x;
	newNode->next = *plist;									/*this node will point to the first node of list*/
	*plist = newNode;									/*external pointer will hold this new node*/
	printf("%d was Inserted at the Begining.",x);
}
void insertLast(NODEPTR *plist, int x)								/*function definition to insert a node at the end of list*/
{
	NODEPTR newNode,temp;									/*variable to hold new and previous node*/
	newNode = malloc(sizeof(struct node));							/*creation of a new node*/
	newNode->next = NULL;
	newNode->info = x;
	if(*plist == NULL)									/*check for empty list*/
		*plist = newNode;								/*External pointer will hold the address of new node*/
	else
	{
		temp = *plist;
		while(temp->next != NULL)							/*Traversing till the last node*/
			temp = temp->next;
		temp->next = newNode;								/*last node will point to the new node*/
	}
	printf("\n%d was Inserted at the End.",x);
}
void insertPos(NODEPTR *plist,int x,int pos)							/*function definition to insert a node at a specified position*/
{
	int i;
	NODEPTR newNode,temp;									/*variable to hold new and previous node*/
	newNode = malloc(sizeof(struct node));							/*creation of new node*/
	if(pos < 1 || pos > ((count(*plist))+1))						/*check for valid position*/
	{
		printf("\nINVALID POSITION\n");
		return;
	}
	if(pos==1)	
	 insertBeg(plist,x);									/*function call to insert node at begining if desired position is 1*/
	else
	{
		temp = *plist;																
		for(i = 0 ; i<(pos-2) ; temp = temp->next , i++)				/*traversing to the node just before the position of node which is specified*/
		 ;
		newNode->next = temp->next;									
		temp->next = newNode;
		newNode->info = x;
	}
	printf("\n%d was Inserted at position %d.",x,pos);
	
}
void insertVal(NODEPTR *plist,int x,int key)							/*function definition to insert a node after a specified value*/
{
	int count = 0;
	NODEPTR newNode,temp;									/*variable to hold new and current node*/
	temp = *plist;
	if(temp == NULL)									/*Check for empty list*/
	{
		insertBeg(plist,x);								/*function call to insert the node as the starting node*/
		return;
	}
	
	/*The following loop will traverse till the last node and will insert node(s) after every node whose value matches with the key*/
	while(temp != NULL)
	{
		if(temp->info == key)
		{
		  count++;									/*Incrementing the counter if the target node is speciified*/
		  newNode = malloc(sizeof(struct node));					/*Creation of new node*/
		  newNode->next = temp->next;
		  temp->next = newNode;
		  newNode->info = x;
	    }
		temp = temp->next;
	}
	if(count == 0)										/*Check if the count value is zero and no node is inserted*/
		printf("\nNode with %d value not found.",key);
	else
		printf("\n%d inserted after node with value %d, %d times",x,key,count);
	
}
void deleteBeg(NODEPTR *plist)									/*function definition to delete a node from the begining of list*/
{
	NODEPTR temp;										/*variable to hold node temporarily*/
	if(*plist == NULL)									/*Check for empty list*/
	{
		printf("\nList Empty.");
		return;
	}
	else
	{
		temp = *plist;									/*Holds the address of first node*/
		*plist = temp->next;								/*External pointer points to node pointed by the first node*/
		printf("\nFirst node with value %d deleted.",temp->info);
		free(temp);									/*releasing the memory occupied by the node*/
	}
	
}
void deleteLast(NODEPTR *plist)									/*function definition to delete a node from the end of list*/
{
	NODEPTR temp,prev;									/*variable to hold node temporarily and previous node*/
	if(*plist == NULL)									/*check for empty list*/
	{
		printf("\nList Empty.");
		return;
	}
	else
	{
		temp = *plist;									/*holds the starting node*/
		prev = NULL;
		while(temp->next != NULL)							/*traversing till the last node of list*/
		{
			prev = temp;								/*holds the current node*/
			temp = temp->next;							/*holds the next node*/
		}
		if(prev == NULL)								/*check if the list contains only one node*/
			*plist = NULL;
		else
			prev->next = NULL;							/*The node before the last node becomes the new last node */
		printf("Value of deleted node is : %d",temp->info);
		free(temp);									/*releasing the memory occupied by the last node*/
	}
}
void deletePos(NODEPTR *plist,int pos)								/*function definition to delete a node at specified position of list*/
{
	int i;
	NODEPTR prevNode,temp;									/*variable to hold the previous node and a temporary node*/
	if(*plist == NULL)									/*check for empty list*/
		printf("\nList Empty.");
		return;
	}
	if(pos < 1 || pos > ( count(*plist) ))							/*check for valid position*/
	{
		printf("\nINVALID POSITION OR EMPTY LIST.\n");
		return;
	}
	if(pos == 1)
		deleteBeg(plist);								/*function call to delete the node at begining if the position is 1*/
	else
	{
		temp = *plist;									/*holds the starting node */
		prevNode = NULL;								/*holds the previous node*/
		for(i = 0 ; i<(pos-1) ; prevNode = temp, temp = temp->next , i++)		/*traversing to the node just before the position of node which is to be deleted*/
		 ;
		prevNode->next = temp->next;
		printf("Value of deleted node is : %d",temp->info);
		free(temp);									/*releasing the memory occupied by the node*/
	}	
}
void deleteVal(NODEPTR *plist,int key)								/*function definition to delete a node(s) with specified value*/
{
	int count = 0;
	NODEPTR prevNode,curr,delNode;								/*variables to hold previous node, current node and the node which is to be deleted*/
	if(*plist == NULL)									/*check for empty list*/
	{
		printf("\nEMPTY LIST.\n");
	}
	else
	{
		prevNode = NULL;								/*holds the previous node*/
		curr = *plist;									/*Initially holds the starting node*/
	    
		/*The following loop will traverse till the last node and will delete node(s) whose value matches with the key*/
		while(curr != NULL)
		{
			if(curr->info == key && curr == *plist)					/*check if the key matches with value and the node is the starting node of list*/
			{
				count++;							/*Incrementing the counter*/
				delNode = curr;							/*holds the node to be deleted*/
				curr = curr->next;						/*current node points to the next node*/
				*plist = curr;							/*External pointer points to the new updated current node*/
				free(delNode);							/*releasing the memory occupied by the node*/
				continue;
			}
			if(curr->info == key && curr != *plist)					/*check if the key matches with value and the node is not the starting node of list*/
			{
				count++;							/*Incrementing the counter*/
				delNode = curr;							/*holds the node to be deleted*/
				prevNode->next = curr->next;					/*previous node will point to the node pointed by the node to be deleted*/
				curr = curr->next;						/*current node points to the next node*/
				free(delNode);							/*releasing the memory occupied by the node*/
				continue;
			}
			prevNode = curr;							/*previous node points to current node*/
			curr = curr->next;							/*current node points to the next node*/
		}
		printf("%d deleted from list %d times.",key,count);
	}
}
void revList(NODEPTR *plist)									/*function definition to reverse the list*/
{
	int ch;
	NODEPTR currNode,prevNode,nextNode;							/*variable to hold current, previous and the next node*/
	if(*plist == NULL)									/*check for empty list*/
	{
		printf("\nEmpty List");
	}
	else
	{
		prevNode = NULL;								/*holds the previosu node*/
		currNode = *plist;								/*Initially holds the starting node*/
		while(currNode->next != NULL)							/*traverse till the last node of list*/
		{
			nextNode = currNode->next;						/*holds the next node*/
			currNode->next = prevNode;						/*current node points to the previosu node*/
			prevNode = currNode;							/*previous node points to current node*/
			currNode = nextNode;							/*current node points to next node*/
		}
		currNode->next = prevNode;							/*last node of initial list will point to its previous node*/
		*plist = currNode;								/*external pointer points to the new starting node(last node of initial list)*/
		printf("\nList Reversed. Press 1 to display the Reversed List : ");		/*choice to print the new reversed list*/
		scanf("%d",&ch);
		if(ch == 1)
			displayList(*plist);							/*function call to display the list*/
	}
}
int count(NODEPTR p)										/*function definition to count the total number of nodes in list*/
{
	int count = 0;
	while(p != NULL)									/*traverse till the last node*/
	{							
		p = p->next;									/*points to the next node*/
		count++;									/*incrementing the counter*/
	}
	return count;										/*returning the value of count*/
}
void displayList(NODEPTR plist)									/*function definition to display the list*/
{
	if (plist == NULL)									/*check for empty list*/
	{
		printf("\nEmpty List");
		return;
	}
	printf("The list is -->\n\n");
	while(plist != NULL)									/*traverse till the last node*/
	{
		printf("%d   ",plist->info);
		plist = plist->next;								/*points to the next node*/
	}
}
