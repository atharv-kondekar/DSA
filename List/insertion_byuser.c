// Insertion

#include<stdio.h>
void shiftDown(int list[],int pos,int lpos)
{
	int curpos=lpos;
	
	while(curpos>=pos)
	{
		list[curpos+1]=list[curpos]; // ShiftDown the data
		curpos--;
	}
}

int insertion(int list[],int pos,int data,int *lpos,int size)
{
	if( *lpos == -1)
	{
		if( pos == 0)
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
		if( *lpos <= size-1 )
		{
			if(pos == *lpos+1 )
			{
				list[pos]=data;
				(*lpos)++;
				return 1;
			}
			
			else if( pos <= *lpos )
			{
				shiftDown(list,pos,*lpos);
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
			return 0;
		}
	}
}
int main()
{
	int n;
	printf("\n Enter the size of List do yo want : ");
	scanf("%d",&n);
	
	int list[n],i,ele;
	printf("\n How Many elements you want to store in list ?: ");
	scanf("%d",&ele);
	if(ele<=n)
	{
		printf("\n Enter the %d elements in an List : ",ele);
		for(i=0;i<ele;i++)
		{
			scanf("%d",&list[i]);
		}
	}
	
	char ch;
	printf("\n Do you want to insert the element in List (y/n) ? : ");
	scanf(" %c",&ch); // // Note the space before %c to consume any leftover newline character
	
	int pos,data;
	if( ch == 'y' || ch == 'Y' )
	{
		printf("\n Enter the index do you want to store the data : ");
		scanf("%d",&pos);
		printf("\n Enter the Data : ");
		scanf("%d",&data);
	

		int lpos=ele-1;
		int size=n;
	
		int check=insertion(list,pos,data,&lpos,size);
	
		if(check == 1)
		{
			printf("\n The %d is successfully stored at %d position",data,pos);
			printf("\n\n The updated list :  ");
			for(i = 0; i <= lpos; i ++)
			{
				printf("\n List[%d]=%d",i,list[i]);
			}
		}
	
		else
		{
			printf("\n We can't Store the data at %d position",pos);
		}
		
	}
	
	else
	{
		printf("\n List without Any changes ");
		for(i=0;i<ele;i++)
		{
			printf("\n List[%d]=%d",i,list[i]);
		}
	}
	
	return 0;
}
