#include<stdio.h>

int fib(int n)
{
	if(n==0)
		return 0;
	
	if(n==1 || n==2 )
		return 1;
	
	int f=0;
	f=fib(n-1)+fib(n-2);
	return f;
}

int main()
{
	int num;
	printf("\n Enter the Number : ");
	scanf("%d",&num);
	
	printf("\n The Fibbinocaai of %d number is %d",num,fib(num));
	
	return 0;
}
