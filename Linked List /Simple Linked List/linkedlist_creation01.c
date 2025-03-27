#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

int main()
{
	int i,j;
	printf("\n Enter the Nodes you want : ");
	scanf("%d",&i);
	
	struct Node * ptr[i];
	ptr[0]=NULL;
	
	for(j=0;j<i;j++)
	{
		ptr[j]=(struct Node *)malloc(sizeof(struct Node));
	}
	
	for(j=0;j<i;j++)
	{
		printf("\n Enter the data of %d Node : ",j+1);
		scanf("%d",&ptr[j]->data);
		
		if( j == i-1 )
		{
			ptr[j]->next=NULL;
		}
		
		else
		{
			ptr[j]->next=ptr[j+1];
		}
	}
	
	struct Node * Temp;
	Temp = ptr[0];
	
	while( Temp != NULL)
	{
		printf("\n The Linked-List[ %d ] = %d",Temp,Temp->data);
		Temp=Temp->next;
	}
	
	printf("\n NULL");
	return 0;
}
