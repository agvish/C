/*Program to find a particular pattern of string in a given text of String by using Knuth-Morris-Pratt Alogorithm.*/
/*Date : 09th August, 2017*/
/*Update 10th October, 2017*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void failureFunc(int*,int,char[]);
void kmpPatternMatch(char[],char[]);
int main()
{
	char txt[200], pat[20];
	int txt_len, pat_len;
	printf("\nEnter the text/string. : ");
	scanf(" %[^\n]",txt);
	printf("\nEnter the pattern to be matched. : ");
	scanf(" %[^\n]",pat);
	kmpPatternMatch(txt,pat);
	return 0;
}
void kmpPatternMatch(char txt[], char pat[])
{
	int *failure;
	int txt_len,pat_len,flag = 0;
	int i = 0,j = 0,count = 0;
	txt_len = strlen(txt);												//Finding lenth of text
	pat_len = strlen(pat);											//Finding length of pattern
	failure = malloc(sizeof(int) * pat_len);								//Memory allocation for failure function array
	failureFunc(failure,pat_len,pat);									//Function call to create Failure function
	
	printf("\nThe Failure Function for the Pattern is : ");	
	for(i = 0 ; i < pat_len ; i++)
		printf(" %d ",failure[i]);
	
	i = 0;
	while(i < txt_len)
	{
		count++;
		if(txt[i] == pat[j])
		{
			if(j == (pat_len - 1))									//Match Found
			{
					printf("\nMatch found at position %d.",(i-j));
					printf("\nNo. of comparision are %d.\n",count);
					return;
			}
			else
			{
				i++;
				j++;
			}
		}
		else 														//No match,but we have advanced
		{
			if(j > 0)
				j = failure[j-1];									//j indexes just after matching prefix of pattern
			else
				i = i + 1;
		}
	}
	if(flag == 0)
	{
		printf("\nNo match found.\n");
	}
}
void failureFunc(int *failure,int pat_len,char pat[])							//Function definition to create Failure function
{
	int i,j;
	failure[0] = 0;
	i = 1; j = 0;
	while(i < pat_len)
	{
		if(pat[i] == pat[j])					//we have matched j+1 characters
		{
			failure[i] = j+1;
			i++;j++;
		}
		else if(j > 0)
			j = failure[j-1];				//use failure function to shift pattern
		else
		{
			failure[i] = 0;					//No match
			i++;
		}
	}
}

