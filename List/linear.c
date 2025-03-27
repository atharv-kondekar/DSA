#include<stdio.h>
int main()
{
	int size;
	printf("\n Enter the size of an array : ");
	scanf("%d",&size);
	
	int Num[size],i,element;
	printf("\n Enter the elements in an array : ");
	for( i=0 ;i < size ; i ++)
	{
		scanf("%d",&Num[i]);
	}
	
	printf("\n Enter the element you want to search : ");
	scanf("%d",&element);
	
	for(i=0;i<size;i++)
	{
		if( Num[i] == element )
			printf("\n The element %d is found at %d index",element,i);
	}
	
	return 0;
}
