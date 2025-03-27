#include<stdio.h>
void shiftUp(int list[],int *ele,int d_ind)
{
	int i;
	
	for(i=d_ind ; i < *ele-1 ; i++)
	{
		list[i]	= list[i+1];
	}
	(*ele)--;
}

int deletion(int list[],int d_ind,int size,int *ele,int *lpos)
{
	if( *lpos == -1 || d_ind < 0 || d_ind >= *ele )
	{
		return 0;
	}
	
	if( *lpos < size )
	{
			shiftUp(list,ele,d_ind);
			(*lpos)--;
			return 1;
	}
		
	else
	{
		return 0;
	}
	
}
int main()
{
	int n;
	printf("\n Enter the size of an array : ");
	scanf("%d",&n);
	
	int list[n],i,ele;
	printf("\n How many elements you want to store in list : ");
	scanf("%d",&ele);
	
	printf("\n Enter the %d elements : ",ele);
	for(i=0;i<ele;i++)
	{
		scanf("%d",&list[i]);
	}
	
	char ch;
	printf("\n Do you want to delete something ? (y/n) : ");
	scanf(" %c",&ch);
	
	if(ch == 'y' || ch == 'Y')
	{
		int d_ind;
		printf("\n Enter the index do you want to delete : ")	;
		scanf("%d",&d_ind);
		
		int lpos=ele-1;
		int size=n;
		
		int check;
		check=deletion(list,d_ind,size,&ele,&lpos);
		
		if( check == 1)
		{
			printf("\n Deleted Successfully  ");
			printf("\n The updated list : ");
			for(i=0;i< ele ;i++)
			{
				printf("\n List [%d] = %d",i,list[i]);
			}
		}
		
		else
		{
			printf("\n We can't delete the data");
		}
	}
	
	else
	{
		printf("\n No Operations on list ");
	}
	
	return 0;
}
