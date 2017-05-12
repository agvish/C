/*Program to calculate Greatest Common Divisor(GCD) of given two number provided as input using Recursion*/

#include<stdio.h>
#include<conio.h>
int gcd(int,int);
int main()
{
    int x,y,result;
    result=0;
    printf("\nEnter the two number.\n");
    scanf("%d%d",&x,&y);
    result=gcd(x,y);
    printf("\nGCD of %d and %d is %d.",x,y,result);
    getch();
    return 0;
}
int gcd(int a,int b)
{
    if(a%b==0)
     return b;
    else
     return gcd(b,a%b);
}
