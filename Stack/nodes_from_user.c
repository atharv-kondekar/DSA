// nodes form the user 

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * CreatingNode(struct Node **Head,int N)
{
	struct Node * tail;
	int i;
	int data;
	
	for(i=0;i<N;i++)
	{
		struct Node * NewNode;
		NewNode=(struct Node *)malloc( sizeof (struct Node ));
		
		if( NewNode == NULL ){
			printf("\n Memory Allocation Failed");
			return NULL;
		}
		
		printf("\n Enter the Data for the %d node : ",i+1);
		scanf("%d",&data);
		
		NewNode->data=data;
		NewNode->next=NULL;
		
		if( *Head==NULL)
		{
			*Head=NewNode;
			tail=NewNode;
		}
		
		else
		{
			tail->next=NewNode;
			tail=NewNode;
		}
	}
}

void traversal(struct Node * Head)
{
	struct Node * curnode=Head;
	
	while(curnode != NULL)
	{
		printf("\n Linked - List [ %d | %p]",curnode->data,curnode->next);
		curnode=curnode->next;
	}
}

int main()
{
	int N;
	printf("\n enter the Nodes you want : ")	;
	scanf("%d",&N);
	
	struct Node * Head = NULL;
	
	CreatingNode(&Head,N);
	traversal(Head);
	return 0;
}
