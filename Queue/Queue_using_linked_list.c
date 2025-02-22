#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * CreateNode()
{
	struct Node * ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node ));
	if( ptr== NULL )
	{
		printf("\n Memory allocation failed ");
		return NULL;
	}
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

void Nodes(struct Node **Front,int nodes,struct Node **Rear )
{
	struct Node * ptr=NULL;
	int i;
	
	for(i=0;i<nodes;i++)
	{
		struct Node * NewNode=CreateNode();
		initNode(NewNode);
		
		if(*Front == NULL )
		{
			*Front=NewNode;
			*Rear=NewNode;
			ptr=NewNode;
		}
		
		else
		{
			ptr->next=NewNode;
			ptr=ptr->next;
		}
		
		*Rear=ptr;
	}
}

int EnQueue(struct Node **Front,struct Node **Rear)
{
	struct Node * NewNode;
	NewNode=CreateNode();
	initNode(NewNode);
	
	struct Node * Last;
	
	if(*Rear == NULL )
	{
		*Rear=NewNode;
		*Front=NewNode;
		return 1;
	}
	
	else
	{
		Last=*Rear;
		Last->next=NewNode;
		*Rear=NewNode;
		return 1;
	}
}

int DeQueue(struct Node **Front , struct Node **Rear,int *val)
{
	if(*Front == NULL )
	{
		return 0;
	}
	
	else
	{
		struct Node * ptr= *Front;
		*val=ptr->data;
		
		if( *Front == NULL )
		{
			*Front=NULL;
			*Rear=NULL;
		}
		
		else
		{
			*Front=ptr->next;
		}

		
		free(ptr);
		return 1;
	}
}

int main()
{
	struct Node * Front = NULL ;
	struct Node * Rear = NULL ;
	
	int nodes;
	printf("\n Enter How many Nodes You Want to create : ");
	scanf("%d",&nodes);
	
	Nodes(&Front,nodes,&Rear);
	
	char MainChoice;
	printf("\n Do you want to perform any opeartions on Queue ? (y/n) : ");
	fflush(stdin);
	scanf("%c",&MainChoice);
	
	if( MainChoice == 'y' || MainChoice == 'Y')
	{
		char ch;
		do
		{
			printf("\n The Following Opeartions you can do on the list ");
			printf("\n EnQueue ");
			printf("\n DeQueue ");
			
			int choice;
			printf("\n Enter Which opearation you want to perform : ");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:
				{
					int status=	EnQueue(&Front,&Rear);
					
					if(status == 1)
					{
						printf("\n Success ");
					}
					
					else
					{
						printf("\n FAIL ");
					}
					
					break;
				}
				
				case 2:
				{
					int val;
					int status=	DeQueue(&Front , &Rear,&val);
					
					if(status == 1)
					{
						printf("\n SUCCESS ");
						printf("\n Val=%d",val);
					}
					
					else
					{
						printf("\n Fail");
					}
					
					break;
				}
				
				default:
					printf("\n Invalid Choice ");
			}
			printf("\n DO you want to cintinue ?(y/n) : ");
			fflush(stdin);
			scanf("%c",&ch);
			
		}while(ch=='y' || ch=='Y');
	}
	return 0;
}
