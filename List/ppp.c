#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node * Next;
};

void Traversal(struct Node * ptr)
{
	while( ptr != NULL )
	{
		printf("\n List = %d",ptr->data);
		ptr=ptr->Next;
	}
}

int main()
{
	struct Node * Head;
	struct Node * Second;
	struct Node * Third;
	struct Node * Fourth;
	
	Head = (struct Node *)malloc( sizeof (struct Node) );
	Second = (struct Node *)malloc( sizeof ( struct Node ));
	Third = (struct Node *)malloc( sizeof ( struct Node ));
	Fourth = (struct Node *)malloc( sizeof ( struct Node ));
	
	printf("\n Enter the Data of Frist Node : ");
	scanf("%d",&Head->data);
	Head->Next = Second;
	
	printf("\n Enter the data of Second Node : ");
	scanf("%d",&Second->data);
	Second->Next = Third;
	
	printf("\n Enter the data of third Node : ");
	scanf("%d",&Third->data);
	Third->Next = Fourth;
	
	printf("\n Enter the data of the last Node : ");
	scanf("%d",&Fourth->data);
	Fourth->Next=NULL;
	
	Traversal(Head);
	
	return 0;
}
