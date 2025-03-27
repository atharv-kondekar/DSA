#include<stdio.h>

int insert(int lis[],int pos,int data,int *lpos,int size)
{
	if(*lpos==-1)
	{
		if(pos==0)
		{
			lis[pos]=data;
			(*lpos)++;
		}
		
		else
		{
			return 0;
		}
	}
	
	else
	{
		if(*lpos<size-1)
		{
			if(pos==*lpos+1)
			{
				lis[pos]=data;
				(*lpos)++;
			}
			
			else
			{
				shiftDown(lis,pos,*lpos);
				lis[pos]=data;
				(*lpos)++;
			}
		}
		
		else
		{
			return 0;
		}
	}
}

void shiftDown(int lis[],int pos,int lpos)
{
	int curpos=lpos;
	
	while(curpos>=pos)
	{
		lis[curpos+1]=lis[curpos];
		curpos--;
	}
}

int main()
{
	int list[100]={10,20,30,40};
	int pos;
	printf("\n Enter the position do you want store the data ");
	scanf("%d",&pos);
	
	int data;
	printf("\n Enter the Data :");
	scanf("%d",&data);
	
	int lpos=3;
	int size=100;
	int in;
	in=insert(list,pos,data,&lpos,size);
	
	if(in==0)
	{
		printf("\n We can't store the data at %d position",pos);
	}
	else
	{
		int i;
		
		printf("\n The updated list: ");
		for(i=0;i<=lpos;i++)
		{
			printf("\n The list[%d]=%d",i,list[i]);
		}
		
		printf("\n The Data is successfully inserted at %d position",pos);
	}
	
	
	return 0;
}


