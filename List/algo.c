#include<stdio.h>

void shiftdown(int list[] , int last , int pos)
{
	int curpos=last;
	while(curpos>=pos)
	{
		list[curpos+1]=list[curpos];
		curpos--;
	}
}

int insert(int list[],int data,int pos,int size,int *last)
{
	if( *last == -1)
	{
		if( pos == 0)
		{
			list[pos]=data;
			(*last)++;
			return 1;
		}
		else
			return 0;
	}
	
	else
	{
		if( *last < size-1 )
		{
			if( pos == *last+1 )
			{
				list[pos]=data;
				(*last)++;
				return 1;
			}
			else
			if( pos <= *last )
			{
				shiftdown(list,*last,pos);
				list[pos]=data;
				(*last)++;
				return 1;
			}
			else
				return 0;
		}
	}
}


void traversal(int list[] , int last)
{
	int i;
	for(i=0;i<=last;i++)
	{
		printf("  %d ",list[i]);
	}
}

int main()
{
	int list[10]={10,20,30,40,50,60};
	int data=96;
	int pos=2;
	int last=5;
	int size=10;
	
	insert(list,data ,pos ,size ,&last);
	traversal(list,last);
}
