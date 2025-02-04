#include<stdio.h>
int main()
{
	int n;
	printf("\n Enter the  n : ");
	scanf("%d",&n);
	
	int i,num[n],j,temp;
	
	printf("\n Enter elements in  an array : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
	
	printf("\n The Sorted Array is :\n");
	for(i=0;i<n;i++)
	{
		printf("\t %d",num[i]);
	}
	
	return 0;
}

