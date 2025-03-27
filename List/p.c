#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

void traversal(struct Node * ptr)
{
	int i=0;
	while( ptr != NULL)
	{
		printf("\n The Linked-List[ %d | next ] = %d ",i,ptr->data);
		printf("\n \t \t | ");
		ptr=ptr->next;
		i++;
	}
	printf("\n \t    NULL");
}

struct Node * insert(struct Node * Head,int data )
{
	struct Node * ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node));
	
	ptr->data=data;
	ptr->next=Head;

	
	return ptr;
}

int main()
{
	int n;
	printf("\n How many Nodes you want ? : ");
	scanf("%d",&n);
	
	struct Node * ptr[n];
	ptr[0]=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		ptr[i]=(struct Node *)malloc(sizeof(struct Node ));
	}
	
	for(i=0;i<n;i++)
	{
		printf("\n Enter the Data of %d Node : ",i+1);
		scanf("%d",&ptr[i]->data);
		
		if( i == n-1 )
			ptr[i]->next=NULL;
		else
			ptr[i]->next=ptr[i+1];
	}
	
	int data;
	printf("\n Enter the data you want to insert : ");
	scanf("%d",&data);
	
	struct Node * temp;//=(struct Node *)malloc(sizeof(struct Node));
	temp=ptr[0];
	
	temp=insert(temp,data);
	traversal(temp);
	
	return 0;
}
