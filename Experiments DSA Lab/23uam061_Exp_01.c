#include<stdio.h>
#include<math.h>

float cal_mean(int num[],int n)
{
	int sum=0;
	int i;
	
	for(i=0;i<n;i++)
	{
		sum=sum+num[i];
	}
	return (float)sum/n;
}

float varience(int num[],int n,float mean)
{
	float varience;
	int i;
	/*
		mean=cal_mean(num,n);
			Instead of writing the (float mean)
	*/
	for(i=0;i<n;i++)
	{
		varience=varience+( (num[i]-mean)*(num[i]-mean) );
	}
	
	varience=varience/n;
	
	return varience;	
}

float sd(int var)
{
	return sqrt(var);
}

int main()
{
	int n;
	printf("\n Enter the size of a array : \n")	;
	scanf("%d",&n);
	
	int num[n],i;
	printf("\n Enter the numbers in an array : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	
	float mean,var,std_dev;
	
	mean=cal_mean(num,n);
	var=varience(num,n,mean);
	std_dev=sd(var);
	
	printf("\n The Mean is 			  : %0.2f",mean);
	printf("\n The Varience is 		  : %0.2f",var);
	printf("\n The Standard Deviation 	  : %0.2f",std_dev);
	
	return 0;
}
