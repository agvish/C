/*Program to find a particular pattern of string in a given text of String by using Bruteforce method.*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void patternMatch(char[],char[]);
int main()
{
	char txt[200], pat[20];
	printf("\nEnter the text/string. : ");
	scanf(" %[^\n]",txt);
	printf("\nEnter the pattern to be matched. : ");
	scanf(" %[^\n]",pat);
	patternMatch(txt,pat);
	return 0;
}
void patternMatch(char txt[], char pat[])
{
	int txt_len,pat_len,flag = 0;
	int i = 0,j = 0,count = 0;
	txt_len = strlen(txt);
	pat_len = strlen(pat);
	while(i <= (txt_len - pat_len))
	{
		while(j < pat_len)
		{
			count++;
			if(txt[i] == pat[j])
			{
				if(j == (pat_len-1))
				{
					printf("\nMatch found at position %d.",(i-j));
					printf("\nNo. of comparision are %d.\n",count);
					return;
				}
				else
				{
					j++;
					i++;
				}
			}
			else
			{
				i = (i - j + 1);
				j = 0;
				break;
			}
		}
	}
	if(flag == 0)
	{
		printf("\nNo match found.");
	}
}
