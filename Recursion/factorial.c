#include<stdio.h>

int factorial(int n)
{
	if( n== 0 || n==1 ){
		return 1; //  base case ( 0! = 1 && 1! = 1 )
	}
	
	
	return ( n * factorial(n-1) );
}

int main()
{
	int number;
	printf("\n Enter the Number : ")	;
	scanf("%d",&number);
	
	printf("\n The factorial of the %d is %d ",number,factorial(number));
	
	return 0;
}
