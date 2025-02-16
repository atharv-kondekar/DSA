#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * createNode()
{
	struct  Node * ptr;
	ptr=(struct Node *)malloc( sizeof(struct Node ));
	return ptr;
}

void initNode(struct Node * ptr)
{
	int data;
	printf("\n Enter the data for the node : ");
	scanf("%d",&data);
	
	ptr->data=data;
	ptr->next=NULL;
}

void traversal(struct Node * ptr)
{
	struct Node * curnode=ptr;
	
	printf("\n\t\t<<<<<<<<<<<<< The Linked List >>>>>>>>>>>>>> ");
	while(curnode!=NULL)
	{
		printf("\n \t\t Linked-List[ %d  |  %d ]",curnode->data,curnode->next);
		printf("\n \t\t\t\t      | ");
		curnode=curnode->next;
	}
	printf("\n \t\t\t\t  NULL\n");
}

struct Node  * insertAtbegin(struct Node * Head )
{
	struct Node * NN;
	NN=createNode();
	initNode(NN);
	
	if( Head == NULL )
	{
		Head=NN;
		return Head;
	}
	
	else
	{
		NN->next=Head;
		Head=NN;
		return Head;
	}
}

struct Node * insertAtEnd(struct Node * Head)
{
	struct Node * NN;
	NN=createNode();
	initNode(NN);
	
	if( Head == NULL )
	{
		Head=NN;
		return Head;
	}
	
	else
	{
		struct Node * tmp=Head;
		
		while(tmp->next != NULL )
		{
			tmp=tmp->next;
		}
		
		tmp->next=NN;
		return Head;
	}
}

struct Node * insertInbeetween(struct Node * Head , int index)
{
	struct Node * NN;
	NN=createNode();
	initNode(NN);
	
	if(index==0)
	{
		NN->next=Head;
		Head=NN;
		return Head;
	}
	
	else
	{
		struct Node * tmp=Head;
		int i=0;
		
		while( i<index-1 && tmp->next!=NULL)
		{
			tmp=tmp->next;
			i++;
		}
		
		NN->next=tmp->next;
		tmp->next=NN;
		return Head;
	}
}

struct Node * InsertAfterNode(struct Node * Head , struct Node * ptr)
{
	struct Node * NN;
	NN=createNode();
	initNode(NN);
	
	NN->next=ptr->next;
	ptr->next=NN;
	
	return Head;
}

int main()
{
	struct Node * Head = NULL;
	struct Node * Frist ;
	struct Node * Second;
	struct Node * Third;
	struct Node * Fourth;
	
	Frist=createNode();
	initNode(Frist);
	Second = createNode();
	initNode(Second);
	Third=createNode();
	initNode(Third);
	Fourth=createNode();
	initNode(Fourth);
	
	Frist->next=Second;
	Second->next=Third;
	Third->next=Fourth;
	
	Head=Frist;
	
	int index;
	char ch;
	do{
			printf("\n  ****** The Following Opeartions you can perform on List ***** ");
			printf("\n \t 1. Insert At Begin ");
			printf("\n \t 2. Insert in Beetween");
			printf("\n \t 3. Insert at the end ");
			printf("\n \t 4. Insert After The Node\n");
	
			int choice;
			printf("\n Enter Which operation you want to perform : ");
			scanf("%d",&choice);
			
		switch(choice)
		{
			case 1:
				Head=insertAtbegin(Head);
				printf("\n \t\t *** Success :- Insertion of Node at begin *** \n");
				traversal(Head);
				break;
			
			case 2:
				printf("\n Enter the index you want to insert the Node : ");
				scanf("%d",&index);
				Head=insertInbeetween(Head ,index);
				printf("\n \t\t *** Success :- Insertion of Node in Between *** \n");
				traversal(Head);
				break;
		
			case 3:
				Head=insertAtEnd(Head);
				printf("\n \t\t *** Success :- Insertion of Node at end *** \n");
				traversal(Head);
				break;
			
			case 4:
				Head=InsertAfterNode(Head , Second);
				printf("\n \t\t *** Success :- Insertion of After the Node *** \n");
				traversal(Head);
				break;
		
			default :
				printf("\n Invalid Choice ");
		}
		
		printf("\n Do you want to Perform any opeartions ? (y/n) : ");
		fflush(stdin);
		scanf("%c",&ch);
		
	}while(ch=='Y' || ch=='y');
	printf("\n Thank you :) ");
	
	return 0;
}
