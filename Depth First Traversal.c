
/*Program to implement Depth First Traversal.*/
#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define explored 2
#define visited 3
void dfs_traversal(int**,int*,int);
void dispMat(int**,int);

int main()
{
	int i,vert,origin,destin;
	int **graph,*state;
	printf("\n********************************DEPTH FIRST TRAVERSAL********************************");
	printf("\nEnter the no. of vertices in the graph. (Vertex starts from 0) : ");
	scanf("%d",&vert);										/*Holding no. of vertices*/
		
	/*Memory allocation for storing graph*/

	graph = malloc(sizeof(int*) * vert);		
	for(i = 0 ; i < vert ; i++)
		graph[i] = malloc(sizeof(int) * vert);
	
	/*Memory allocation for storing state of each vetex.(Initial/Explored/Visited).*/

	state = malloc(sizeof(int) * vert);
	for(i = 0 ; i < vert ; i++)
		state[i] = initial;									/*By default all vertex are at inital state*/
	
	printf("\nEnter the adjacency matrix for graph. \n\nEnter the Orgin Vertex and Destination Vertex.\n\n");
	for(i = 0 ; i < vert*vert ; i++)
	{
		printf("Enter edge %d(-1 -1 to quit ) : ",(i+1));
		scanf("%d %d",&origin,&destin);
		if((origin == -1) && (destin == -1))							/*Condition to terminate the input of graph*/
			break;
		if(origin >= vert || destin >= vert || origin < 0 || destin < 0)			/*If value of origin and destination vertex provided are invalid*/
		{
			printf("\nInvalid edge\n");
			i--;
		}
		else
		{
			graph[origin][destin]=1;
			graph[destin][origin]=1;
		}
	}
	printf("The adjacency matrix according to the given input is : \n");
	dispMat(graph,vert);										/*Function call to display graph in adjacency matrix form*/
	printf("\n");
	dfs_traversal(graph,state,vert);								/*Function call for Depth First Search*/
	printf("\n");	
	return 0;
}
void dfs_traversal(int **graph , int *state , int vert)
{
	int start , i , top = -1 , v , failure = 0;
	int *stack;
	printf("\nEnter the starting vertex. : ");
	scanf("%d",&start);										/*Holding the starting vertex*/
	for(i = 0 ; i < vert ; i++)								/*If starting vertex is not connected to Graph*/
	{
		if(graph[start][i] == 0)
			failure++;
	}
	if(start >= vert || failure == vert)
	{
		printf("\nInvalid Vertex / Vertex not connected to Graph.\nEXITING.\n");
		exit(1);
	}

	if(start >= vert)
	{
		printf("\nInvalid Edge.\nEXITING.\n");
		exit(1);
	}
	stack = malloc(sizeof(int) * vert);								/*Memory allocation for stack*/
	stack[++top] = start;										/*Pushing the starting vertex to stack*/
	state[start] = explored;									/*Changing the state of starting vertex*/
	printf("\nDFS of graph is :\n");
	while(top !=  -1)										/*while stack is empty*/
	{
		v = stack[top--];									/*Popping the vertex from stack*/
		printf("%d ",v);									/*Printing the dequeued vertex*/
		state[v]=visited;									/*Changing the state of popped vertex*/
		for(i = 0 ; i < vert ; i++)
		{
			if(graph[v][i] ==1 && state[i]==initial)					/*Searching for adjacent vertex of popped vertex which are not yet visited*/
			{
				stack[++top] = i;							/*Pushing the not yet 'adjacent visited' vetex*/
				state[i] = explored;							/*Changing the state to explored*/
			}
		}
	}
}
void dispMat(int **mat , int vert)
{
	int i , j;
	for(i = 0 ; i < vert ; i++)
	{
		for(j = 0 ; j < vert ; j++)
		{
			printf("%d \t", mat[i][j]);
		}
		printf("\n");
	}
}

