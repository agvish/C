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
	int txt_len,pat_len;
	int i = 0,j = 0,count = 0;								/*'i' is at 0th position of text 'j' is at 0th position of pattern 'count' holds total no. of comparision made*/
	txt_len = strlen(txt);									/*Calculate length of input 'text' string*/
	pat_len = strlen(pat);									/*Calculate length of input 'pattern' string*/
	while(i <= (txt_len - pat_len))
	{
		while(j < pat_len)
		{
			count++;
			if(txt[i] == pat[j])
			{
				if(j == (pat_len-1))						/*If 'j' has reached at the last character of pattern*/
				{
					printf("\nMatch found at position %d.",(i-j));
					printf("\nNo. of comparision are %d.\n",count);
					return;
				}
				else
				{
					j++;							/*Increment both 'i' and 'j'*/
					i++;
				}
			}
			else									/*Encounter a mis match in text and pattern*/
			{
				i = (i - j + 1);						/*'i' is now positioned back at '(j+1)' characters of text string */
				j = 0;								/*'j' is now positioned at starting of pattern string*/
				break;
			}
		}
	}
	printf("\nNo match found.");
}
