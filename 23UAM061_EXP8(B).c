#include<stdio.h>
int sorted(int list[] ,int ele)
{
	int i;
	for(i=0;i<ele-1;i++)
	{
		if( list[i] > list[i+1])
		{
			return -1;
		}
	}
	
	return 1;
}

int BinarySearch(int list[],int ele,int SearchElement)
{
	int low,mid,high;
	low=0;
	high=ele-1;

	
	while(low <= high)
	{
		mid=(low+high)/2;
	
		if( list[mid] == SearchElement)
		{
			return mid;
		}
		else if( list[mid] > SearchElement )
		{
			high = mid-1;
		}
		
		else
		{
			low= mid + 1;
		}
	}
	
	return -1;
}
int main()
{
	int size;
	printf("\n Enter the size of list : ");
	scanf("%d",&size);
	
	int list[size];
	int i,ele;
	printf("\n Enter the elements you want to enter : ");
	scanf("%d",&ele);
	
	printf("\n Enter the elements in an list : ");
	for(i=0;i<ele;i++)
	{
		scanf("%d",&list[i]);
	}
	int SearchElement;
	if( sorted(list,ele) == 1 )
	{
		printf("\n The List is Sorted :) ");
		printf("\n Enter the Element you want to search: ");
		scanf("%d",&SearchElement);
		
		int index =BinarySearch(list,ele,SearchElement);
		if(index != -1)
		{
			printf("\n The Data %d is found at %d index",SearchElement,index);
		}
		
		else
			printf("\n The Data is Not found in the list ");
	}
	
	else
		printf("\n The list is not sorted");
		
	return 0;
}
