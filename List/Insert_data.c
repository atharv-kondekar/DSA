#include<stdio.h>
int insert(int list[],int pos,int data,int size,int *lpos)
{
	if(*lpos == -1)
	{
		if(pos == 0)
		{
			list[pos]=data;
			(*lpos)++;
			return 1;
		}
		
		else
		{
			return 0;
		}
	}
	
	else
	{
		if(*lpos < size-1)
		{
			if(pos == *lpos+1 )
			{
				list[pos] = data;
				(*lpos)++;
				return 1;
			}
			
			else 
			{
				if(pos <= *lpos )
				{
					shiftDown(list,pos,*lpos);
					list[pos] = data;
					(*lpos)++;
					return 1;
				}
				
				else
				{
					return 0;
				}
				
			}
			
			
		}
		
		else 
		{
			return 0;
		}
	}
	
}

void shiftDown(int list[],int pos,int lpos)
{
	int curpos=lpos;
	
	while(curpos >= pos)
	{
		list[curpos + 1] = list[curpos];
		curpos --;
	}
}
int main()
{
	int list[100]={10,20,30,60};
	int lpos=3;
	int size=100;
	int pos;
	printf("\n Enter the Index do you want to store the data : ");
	scanf("%d",&pos);
	
	int data;
	printf("\n Enter the data : ");
	scanf("%d",&data);
	int in=insert(list, pos, data, size, &lpos);
	
	if(in == 0)
	{
		printf("\n We can't store the Data at %d position",pos);
	}
	else
	{
		int i;
		printf("\n The Updated List : ");
		for(i = 0;i <= lpos;i++)
		{
			printf("\n List[%d]=%d",i,list[i]);
		}
	}
	
	
	return 0;
}
