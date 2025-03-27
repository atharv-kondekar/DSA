#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node * next;
};

void traversal(struct Node *);

int main()
{
	struct Node * head = NULL;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;
	
	head	=(struct Node *)malloc(sizeof(struct Node));
	second	=(struct Node *)malloc(sizeof(struct Node));
	third	=(struct Node *)malloc(sizeof(struct Node));
	fourth	=(struct Node *)malloc(sizeof(struct Node));
	
	printf("\n Enter the data of frist Node : ");
	scanf("%d",&head->data);
	head->next = second;
	
	printf("\n Enter the data of the Second Node : ");
	scanf("%d",&second->data);
	second->next = third;
	
	printf("\n Enter the data of the Third Node : ");
	scanf("%d",&third->data);
	third->next=fourth;
	
	printf("\n Enter the data of the fourth Node : ");
	scanf("%d",&fourth->data);
	fourth->next=NULL;
	
	traversal(head);
	
	return 0;
}

void traversal(struct Node * ptr)
{
	while( ptr != NULL )
	{
		printf("\n LINKED_LIST[ %d ] = %d",ptr,ptr->data);
		ptr=ptr->next;
	}
}



/*#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data ;
	struct Node * next ;
};

void traverse(struct Node * ptr)
{
	while( ptr != NULL)
	{
		printf("\n %d",ptr->data);
		ptr=ptr->next;
	}
}

int main()
{
	struct Node * Head;
	struct Node * Second;
	struct Node * Third;
	
	Head   = (struct Node *)malloc( sizeof (struct Node) );
	Second = (struct Node *)malloc( sizeof (struct Node) );
	Third  = (struct Node *)malloc( sizeof (struct Node) );
	
	//Head->data=10;
	printf("\n Enter the data : ");
	scanf("%d",& Head->data);
	Head->next=Second;
	
	Second->data=18;
	Second->next=Third;
	
	Third->data = 96;
	Third->next = NULL;
	
	traverse(Head);
	
	return 0;
}*/
