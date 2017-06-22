#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node									/*Structure Definition for node*/
{
	int info;
	struct node *left;
	struct node *right;
};
typedef struct node *NODEPTR;

void insert(NODEPTR*, int);								/*function prototype to insert a node in tree*/
void deleteNode(NODEPTR*, int);							/*function prototype to delete a node from tree*/
void preorder(NODEPTR);								/*function prototype to perform preorder traversal*/
void postorder(NODEPTR);								/*function prototype to perform postorder traversal*/
void inorder(NODEPTR);								/*function prototype to perform inorder traversal*/
int countNode(NODEPTR);								/*function prototype to count total number of nodes in a tree*/
int treeHeight(NODEPTR);								/*function prototype to calculate height of tree*/
int max(int, int);
int search(NODEPTR, int);								/*function prototype to search for a particular node value*/
int main()
{
	struct node *bst;
	int ch,x,count,height,src = 0;
	bst = NULL;
	do{
		printf("\n\n1. Insert a NODE in the BST.");
		printf("\n2. Delete a NODE from the BST.");
		printf("\n3. Preorder Traversal.");
		printf("\n4. Postorder Traversal.");
		printf("\n5. Inorder Traversal.");
		printf("\n6. Count total number of NODES in the BST.");
		printf("\n7. Calculate the height of BST.");
		printf("\n8. Search for a NODE value");
		printf("\n0. EXIT.");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: printf("\nTHANKYOU");
					break;
			case 1: printf("\nEnter a NODE value : ");
					scanf("%d",&x);
					insert(&bst,x);				/*function call to insert a node into the BST*/
					break;
			case 2: printf("\Enter a NODE value to be removed : ");
					scanf("%d",&x);
					deleteNode(&bst,x);				/*function call to remove a node from the BST*/
					break;
			case 3: printf("\nPreorder Traversal results in : ");
					preorder(bst);				/*function call to perform PREORDER traversal*/
					break;
			case 4: printf("\nPostorder Traversal results in : ");
					postorder(bst);				/*function call to perform POSTORDER traversal*/
					break;
			case 5: printf("\nInorder Traversal results in : ");
					inorder(bst);				/*function call to perform INORDER traversal*/
					break;
			case 6: count = countNode(bst);				/*function call to count total number of nodes in BST*/
					printf("\nThere are %d nodes in the BST.",count);
					break;
			case 7: height = treeHeight(bst);					/*function call to calculate height of BST*/
					printf("\nThe height of BST is %d",height);
					break;
			case 8: printf("\nEnter a NODE value to be searched : ");
					scanf("%d",&x);
					src = search(bst,x);				/*function call to search for a node value.*/
					if(src == 0)
						printf("\nUnsuccessful Search.");
					else
						printf("\nSuccessful Search.");
					break;
			default: printf("\nWrong Choice.");
		}
	}while(ch != 0);
	getch();
	return 0;
}
void insert(NODEPTR *proot,int val)							/*function definition to insert a node in the BST*/
{
	NODEPTR newNode, currNode;							/*variable to hold new and current node*/
	int found=0, flag = 0;
	found = search(*proot,val);							/*function call top search a value*/
	if(found == 1)								/*check for duplicate values*/
	{
		printf("\nNode with value %d is already present in BST.\nTry Again!.",val);
		return;
	}
	newNode = (NODEPTR)malloc(sizeof(struct node));
	newNode->info = val;
	newNode->left = NULL;
	newNode->right = NULL;
	if(*proot == NULL)								/*Check for empty BST*/
	{
		*proot = newNode;
	}
	else
	{
		currNode = *proot;							/*Holds the root of the BST*/
		do
		{
			if(val < currNode->info)					/*Check for value less than value in current node*/
			{
				if(currNode->left != NULL)				/*move left of BST*/
					currNode = currNode->left;
				else
				{
					currNode->left = newNode;			/*Insert as the left child of node*/
					flag = 1;
				}
			}
			if(val > currNode->info)					/*check if value is greater than value in current node*/
			{
				if(currNode->right != NULL)
					currNode = currNode->right;			/*move right of BST*/
				else
				{
					currNode->right = newNode;			/*insert as right child of node*/
					flag = 1;
				}
			}
		}while(flag != 1);
	}
	printf("\nNode with value %d inserted.\n",val);
}
void deleteNode(NODEPTR *proot, int val)							/*function definition to delete a node from BST*/
{
	int found = 0, flag = 0;
	NODEPTR delNode, currNode, parent, insucc, pinsucc, temp, leftchild;
	found = search(*proot,val);							/*function call to search a value*/
	if(found == 0)								/*check whether the value to be deleted is present or not.*/
	{
		printf("\nNode with value %d not found.",val);
		return;
	}
	if(*proot == NULL)
	{
		printf("\nEMPTY BST");
		return;
	}
	currNode = *proot;								/*holds the current node*/
	parent = NULL;								/*holds the parent node*/
	insucc = pinsucc = NULL;
	do
	{
		if(currNode->info == val)						/*check if the node value matches*/
		{
			flag = 1;
			delNode = currNode;
			if(currNode->left == NULL && currNode->right == NULL)		/*check for leaf node*/
			{
				if(parent->right == currNode)				/*check whether the node was right child of its parent*/
					parent->right = NULL;									
				else						/*check whether the node was left child of its parent*/
					parent->left = NULL;
				break;
			}
			if(currNode->left == NULL || currNode->right == NULL)		/*check for node having only one child*/
			{
				if(currNode->left == NULL)				/*check for node having only right subtree*/
				{
					if(parent->right == currNode)			/*check whether the current node was right child of its parent*/
						parent->right = currNode->right;
					else					/*check whether the current node was left child of its parent*/
						parent->left = currNode->right;
				}
				else						/*check for node having only left subtree*/
				{
					if(parent->right == currNode)			/*check whether the current node was right child of its parent*/
						parent->right = currNode->left;
					else					/*check whether the current node was left child of its parent*/
						parent->left = currNode->left;
				}
				break;
			}
			else
			{
				insucc = currNode->left;				/*holds the left child of the node to be deleted*/
				while(insucc->right != NULL)				/*finds the inorder successor of the node to be deleted*/
				{
					pinsucc = insucc;				/*holds the parent of successor node*/
					insucc = insucc->right;
				}
				if(parent != NULL)					/*check if the node to be deleted is root node*/
				{
					if(parent->right == currNode)
						parent->right = insucc;
					else
						parent->left = insucc;
				}
				else
					*proot = insucc;
				insucc->right = currNode->right;				/*right subtree of deleted node becomes right subtree of successor node*/
				if(currNode->left != insucc)				/*check whether the left child of deleted node is the only successor*/
				{	
					leftchild = insucc->left;			/*holds left child of successor node*/
					temp = currNode->left;			/*holds left subtree of the deleted node*/
					while(leftchild->left != NULL)			/*finds the leftmost child of the inorder successor*/
						leftchild = leftchild->left;
					leftchild->left = temp;				/*assigns the left subtree of deleted node as left child of the successor*/
				}
				if(pinsucc != NULL)					/*check if there is a parent of successor node*/
					pinsucc->right = NULL;
				break;
			}
		}
		parent = currNode;							/*update parent node*/
		if(currNode->info < val)						/*check if the value to be deleted is greater than current node value*/
			currNode = currNode->right;
			
		if(currNode->info > val)						/*check if the value to be deleted is less than current node value*/
			currNode = currNode->left;
	}while(flag != 1);
	
	printf("\nNode with value %d deleted.",val);
	
	free(delNode);
}
void preorder(NODEPTR proot)								/*function definition for PREORDER traversal*/
{
	if(proot == NULL)
		return;
	printf(" %d", proot->info);							/*Print the node value*/
	preorder(proot->left);								/*recursive call to left child*/
	preorder(proot->right);							/*recursive call to right child*/
}
void postorder(NODEPTR proot)							/*function definition for POSTORDER traversal*/
{
	if(proot == NULL)
		return;
	postorder(proot->left);							/*recursive call to left child*/
	postorder(proot->right);							/*recursive call to right child*/
	printf(" %d", proot->info);							/*print the node value*/
}
void inorder(NODEPTR proot)								/*function definition for INORDER traversal*/
{
	if(proot == NULL)
		return;
	inorder(proot->left);								/*recursive call to left child*/
	printf(" %d", proot->info);							/*print the node value*/
	inorder(proot->right);							/*recursive call to right child*/
}
int countNode(NODEPTR proot)							/*function definition to count total nodes present in BST*/
{
	if(proot == NULL)								/*check for empty BST*/
		return 0;
	else
		return 1 + countNode(proot->left) + countNode(proot->right);
}
int treeHeight(NODEPTR proot)								/*function definition to calculate height of BST*/
{
	if(proot == NULL)								/*check for empty bst*/
		return 0;
	else
		return max(treeHeight(proot->left),treeHeight(proot->right)) + 1;
}
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int search(NODEPTR proot, int key)							/*function definition to search for a particular node*/
{
	if(proot == NULL)								/*check for empty BST*/
		return 0;
	while(proot != NULL)
	{
		if(key < proot->info)							/*check whether value is less than current node's value*/
			proot = proot->left;
		else if(key > proot->info)						/*check whether value is more than current node's value*/
			proot = proot->right;
		else			
			return 1;							/*value found*/
	}
	return 0;									/*unsuccessful search.*/
}
