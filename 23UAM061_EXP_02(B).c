#include<stdio.h>
int main()
{
	int n;
	printf("\n Enter the n : ");
	scanf("%d",&n);
	
	int num[n],i,j,temp,min;
	
	printf("\n Enter the numbers in an array : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	
	for(i=0;i<n-1;i++)
	{
		min=i;
		
		for(j=i+1;j<n;j++)
		{
			if(num[min]>num[j])
			{
				min=j;
			}
		}
		
		if(min!=i)
		{
			temp=num[i];
			num[i]=num[min];
			num[min]=temp;
		}
	}
	
	printf("\n The sorted array is : \n");
	for(i=0;i<n;i++)
	{
		printf("\t %d",num[i]);
	}
	
	return 0;
}


