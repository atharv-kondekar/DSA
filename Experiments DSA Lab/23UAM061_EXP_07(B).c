
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * CreateNode()
{
	struct Node * ptr;
	ptr = (struct Node *)malloc(sizeof(struct Node ));
	if(ptr == NULL)
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
	
	ptr->data = data;
	ptr->next = NULL;
}

void Nodes(struct Node **Front, int nodes, struct Node **Rear)
{
	struct Node * ptr = NULL;
	int i;
	
	for(i = 0; i < nodes; i++)
	{
		struct Node * NewNode = CreateNode();
		initNode(NewNode);
		
		if(*Front == NULL)
		{
			*Front = NewNode;
			*Rear = NewNode;
			ptr = NewNode;
		}
		else
		{
			ptr->next = NewNode;
			ptr = ptr->next;
		}
		
		*Rear = ptr;
	}
}

int EnQueue(struct Node **Front, struct Node **Rear)
{
	struct Node * NewNode = CreateNode();
	initNode(NewNode);
	
	if(*Rear == NULL)
	{
		*Rear = NewNode;
		*Front = NewNode;
		return 1;
	}
	else
	{
		(*Rear)->next = NewNode;
		*Rear = NewNode;
		return 1;
	}
}

int DeQueue(struct Node **Front, struct Node **Rear, int *val)
{
	if(*Front == NULL)
	{
		return 0; // Queue is empty
	}
	else
	{
		struct Node * ptr = *Front;
		*val = ptr->data;
		
		if(*Front == *Rear) // If there's only one node
		{
			*Front = NULL;
			*Rear = NULL;
		}
		else
		{
			*Front = ptr->next;
		}
		
		free(ptr);
		return 1;
	}
}

int main()
{
	struct Node * Front = NULL;
	struct Node * Rear = NULL;
	
	int nodes;
	printf("\n Enter How many Nodes You Want to create (initial queue size): ");
	scanf("%d",&nodes);
	
	Nodes(&Front, nodes, &Rear);
	
	char MainChoice;
	printf("\n Do you want to perform any operations on the Queue? (y/n): ");
	fflush(stdin);
	scanf("%c", &MainChoice);
	
	if(MainChoice == 'y' || MainChoice == 'Y')
	{
		char ch;
		do
		{
			printf("\n The Following Operations you can perform on the list:");
			printf("\n 1. EnQueue ");
			printf("\n 2. DeQueue ");
			
			int choice;
			printf("\n Enter which operation you want to perform: ");
			scanf("%d", &choice);
			
			switch(choice)
			{
				case 1:
				{
					int status = EnQueue(&Front, &Rear);
					
					if(status == 1)
					{
						printf("\n EnQueue Success ");
					}
					else
					{
						printf("\n EnQueue Fail ");
					}
					
					break;
				}
				
				case 2:
				{
					int val;
					int status = DeQueue(&Front, &Rear, &val);
					
					if(status == 1)
					{
						printf("\n DeQueue Success ");
						printf("\n Value dequeued: %d", val);
					}
					else
					{
						printf("\n DeQueue Fail (Queue is empty)");
					}
					
					break;
				}
				
				default:
					printf("\n Invalid Choice ");
			}
			printf("\n Do you want to continue? (y/n): ");
			fflush(stdin);
			scanf("%c", &ch);
			
		} while(ch == 'y' || ch == 'Y');
	}
	return 0;
}

