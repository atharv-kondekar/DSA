#include<stdio.h>

void sort(int Num[],int n)
{
	int i,j,min,temp;
	
	for(i=0;i<n-1;i++)
	{
		min=i;
		
		for(j=i+1;j<n;j++)
		{
			if(Num[min] > Num[j])
			{
				min=j;
			}
		}
		
		if(min!=i)
		{	
			temp=Num[i];
			Num[i]=Num[min];
			Num[min]=temp;
		}
	}
	

}

int main()
{
	int n;
	printf("\n How Mnay Numbers you want to store in your arry ? : ");
	scanf("%d",&n);
	
	int Num[n],i;
	printf("\n Enter the %d Numebrs in your array ",n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the Number %d : ",i+1);
		scanf("%d",&Num[i]);
	}
	
	printf("\n The Array Before the sort : ");
	for(i=0;i<n;i++)
	{
		printf("\n Num[%d]=%d",i,Num[i]);
		
	}
	
	sort(Num,n);
	
	printf("\n\n The Array After the sort : ");
	
	for(i=0;i<n;i++)
	{
		printf("\n Num[%d]=%d",i,Num[i]);
		
	}
	
	return 0;
}
