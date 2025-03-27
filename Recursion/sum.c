#include<stdio.h>

int sum(int n)
{
	int s=0;
	
	if(n==1)
		return 1;
	
	s=n+sum(n-1);
	return s;
}

int main()
{
	int num;
	printf("\n Enter the Number : ");
	scanf("%d",&num);
	
	printf("\n The sum of digits of %d number = %d",num,sum(num));
	
	return 0;
}
