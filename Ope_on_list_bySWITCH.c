#include<stdio.h>
void display(int list[],int n)
{
	printf("\n The Updated list is : ");
	int i;
	for(i=0;i<=n;i++)
	{
		printf("\n List[ %d ] = %d",i,list[i]);
	}
}

void traverse(int list[],int n)
{
	printf("\n The Traverse list : ");
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n List[ %d ] = %d",i,list[i]);
	}
}

void shiftup(int list[],int d_ind,int lpos)
{
	int i;
	for(i=d_ind ; i<= lpos ; i++ )
	{
		list[i]=list[i+1];
	}
	
}

int deletion(int list[],int *lpos,int size,int d_ind)
{
	if( *lpos == -1 || d_ind > *lpos || d_ind < 0)
		return 0;
	
	else 
	if( *lpos < size  )
	{
		shiftup(list,d_ind,*lpos);
		(*lpos)--;
		return 1;
	}
	
	else
		return 0;
}

void shiftDown(int list[],int pos,int lpos)
{
	int curpos=lpos;
	while( curpos >= pos)
	{
		list[curpos+1]=list[curpos];
		curpos --;
	}
}

int insert(int list[],int pos,int data,int *lpos,int size)
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
			return 0;
	}
	
	else
	{
		if( *lpos <size-1 )
		{
			if( pos == *lpos+1 )
			{
				list[pos]=data;
				(*lpos)++;
				return 1;
			}
			else
			if( pos <= *lpos )
			{
				shiftDown(list,pos,*lpos);
				list[pos]=data;
				(*lpos)++;
				return 1;
			}
			
			else
				return 0;
		}
		
		else
			return 0;
	}
}

int main()
{
	int n;
	printf(" \n Enter the total size of list : ");
	scanf("%d",&n);
	
	int list[n],i,ele;
	printf("\n Enter How many elements you want to store in list ? : ");
	scanf("%d",&ele);
	
	if(ele > n)
		printf("\n Error : Not enough space to store the elements");
	
	printf("\n Enter the %d elements : ",ele);
	for(i=0 ; i<ele ; i++)
	{
		scanf("%d",&list[i]);
	}
	int lpos=ele-1;
	int size=n;
	char ch1;
	printf("\n Do Want to perfrom any operation on list ? (y/n) : ");
	scanf(" %c",&ch1);
	
	if( ch1 == 'y' || ch1 == 'Y' )
	{
		printf("\n The Following Operations you can perform ");
		printf("\n 1. Insert Data");
		printf("\n 2. Delete Data");
		printf("\n 3. Traverse List");
		
		int choice;
		printf("\n Which Operation you want perform ? : ");
		scanf("%d",&choice);
		
		int data,pos,check; // for insertion
		int d_ind,checkin; // for deletion
		
		switch(choice)
		{
			case 1:
				printf("\n Enter the index you want to store the data : ");
				scanf("%d",&pos);
				printf("\n Enter the data you want to insert : ");
				scanf("%d",&data);
				
				check=insert(list,pos,data,&lpos,size);
					switch(check)
						{
							case 1:
								printf("\n The data inserted Succfully");
								display(list,lpos);
								break;
								
							default:
								printf("\n We can't Insert the data");
						}
				break;
			
			case 2:
				
				printf("\n Enter the Index at which you want to delete data : ");
				scanf("%d",&d_ind);
				
				checkin=deletion(list,&lpos,size,d_ind);
					switch(checkin)
					{
						case 1:
							printf("\n The data is deleted succeffully");
							display(list,lpos);
							break;
						
						default:
							printf("\n We can't delete the data ");
					}
				break;
				
			case 3:
				traverse(list,ele);
				break;
			
			default:
				printf("\n Inavlid Choice");
		}
	}
	
	else
		printf("\n Thank You :) ");
		
	return 0;
}

/*
*lpos++: Access the value at the current pointer location, then increment the pointer.
(*lpos)++: Access the value at the current pointer location and increment the value itself; the pointer remains unchanged.
*/
