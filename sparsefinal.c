/* 09.02.2017 
Compressed storage representation of a sparse matrix and transpose of a sparse matrix */
/* (Let us assume that the elements of the array are integers so that we can use a 2d array
to store the compressed representation and transpose) */

#include<stdio.h>
#include<stdlib.h>

int** createMatrix(int,int);        /* prototype to allocate memory for a matrix */
void inputMatrix(int **,int,int);   /* prototype to populate matrix */
void displayMatrix(int **,int,int); /* prototype to display elements of the matrix */
int count(int **,int,int);          /* prototype to count non-zero elements of a matrix */
int** sparse(int **, int,int);      /* prototype to store a matrix in compressed form */ 
int** transposeSp(int **);          /* prototype to transpose a sparse matrix */ 

int main(void)
{
	int row,col,i;
	int **mat, **a, **b;                                     /* a holds the compressed representation, b holds the transpose */
	
	printf("Enter the order of matrix (row and column):\n");
	scanf("%d%d",&row,&col);
    mat=createMatrix(row,col);                                /*function call to create/allocate memory for 'mat' */
		
	printf("Enter elements of the matrix:\n");
	inputMatrix(mat,row,col);                                  /*function call to input elements in 'mat' */
		
	printf("The given matrix is:\n");
	displayMatrix(mat,row,col);                                  /*function call to display the matrix */
	i=count(mat,row,col);
    if((row*col)>((i+1)*3))
    {	
	 a=sparse(mat,row,col);                                       /*function call to 'sparse' */	
     free(mat);                                                  /*function call to deallocate the memory for 'mat' */
	
	 printf("\nCompressed representation\n");
	 displayMatrix(a,col,3);                             /* function call to display the compressed representation */
	
     b=transposeSp(a);                                                 /* function call to 'transposeSp' */
	
	 printf("\nTranspose \n");
	 displayMatrix(b,col,3);                            /* function call to display the transposed compressed matrix */
	}
    getch();
	return 0;
}
int** createMatrix(int r,int c)/* function definition for createMatrix */
{
      int **a,i;
      a=malloc(sizeof(int*)*r);
      for(i=0;i<r;i++)
      {
         a[i]=malloc(c*sizeof(int));
      }
      return a;
}
void inputMatrix(int **a,int r,int c)/*function definition for inputMatrix */
{
   int i,j;
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       {
             scanf("%d",&a[i][j]);
       }
   }
}
void displayMatrix(int **a,int r,int c)/*function definition for displayMatrix */
{
     int i,j;
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       {
             printf("%d ",a[i][j]);
       }
       printf("\n");
   }
}

int count(int **a,int r,int c)/* function definition of count */
{
    int i,j,nz;
    nz=0;
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
      {
         if(a[i][j]!=0)
          nz++;
      }
    }
    return nz;
}
int** sparse(int **sp, int r,int c)/*function definition of sparse */
{
      int i,j,row,col;;
      int nz=count(sp,r,c);
      int **SP;
      SP=createMatrix(c,3);
      SP[0][0]=r;
      SP[0][1]=c;
      SP[0][2]=nz;
      row=1;
      col=0;
      for(i=0;i<r;i++)
      {
       for(j=0;j<c;j++)
       {
         if(sp[i][j]!=0)
         {
           SP[row][col]=i;
           col++;
           SP[row][col]=j;
           col++;
           SP[row][col]=sp[i][j];
           col=0;
           row++;
         }
       }
      }
      return SP;
}
int** transposeSp(int **sp1)/* function definition of transposeSp */
{
      int **SP1;
      int i,j,c,x;
      c=sp1[0][1];
      SP1=createMatrix(c,3);
      SP1[0][0]=sp1[0][1];
      SP1[0][1]=sp1[0][0];
      SP1[0][2]=sp1[0][2];
      j=1;
      for(x=0;x<(sp1[0][1]);x++)
      {         
       for(i=1;i<(sp1[0][1]);i++)
       {
                        
         if(sp1[i][1]==x)
         {
           SP1[j][0]=sp1[i][1];
           SP1[j][1]=sp1[i][0];
           SP1[j][2]=sp1[i][2];
           j++;
         }
       }
      }
      return SP1;
}
           
