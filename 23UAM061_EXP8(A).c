#include<stdio.h>
int LinearSearch(int arr[],int Size,int Ele)
{
	int i;
	for(i=0;i<Size;i++)
	{
		if( arr[i] == Ele)
			return i;
	}
	return -1;
}
int main()
{
	int Size;
	printf("\n Enter the size of an array : ");
	scanf("%d",&Size);
	
	int Num[Size],i,Ele;
	printf("\n Enter the elements in an array : ");
	for(i=0;i<Size;i++)
	{
		scanf("%d",&Num[i]);
	}
	
	printf("\n Enter the element you want to search : ");
	scanf("%d",&Ele);
	
	int check = LinearSearch(Num,Size,Ele);
	
	if(  check == 1)
		printf("\n The element %d is found at %d index",Ele,check);
	
	else
		printf("\n The element is not found");
	
	return 0;
}
