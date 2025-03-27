#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * createNode()
{
	struct Node * ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node ));
	return ptr;
}

void initNode(struct Node * ptr)
{
	int data;
	printf("\n Enter the data for thr node : ");
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
		printf("\n \t\t Linked-List[ %d  |  %p ]",curnode->data,curnode->next);
		printf("\n \t\t\t\t      | ");
		curnode=curnode->next;
	}
	printf("\n \t\t\t\t  NULL\n");
}

int detachAtBegin(struct Node **head)
{
	if( *head==NULL )
	{
		return -1;
	}
	
	else
	{
		struct Node * tmp=*head;
		*head=tmp->next;
		int data=tmp->data;
		free(tmp);
		return data;
	}
}


int detachAtindex(struct Node **head ,int index)
{
	if( *head== NULL )
	{
		return -1;
	}
	
	else if(index==0)
	{
		detachAtBegin(head);
	}
	else
	{
		struct Node * tmp=*head;
		int i;
		while( i<index-1)
		{
			tmp=tmp->next;
			i++;
		}
		struct Node * ptr = tmp->next;
		tmp->next=ptr->next;
		int data=ptr->data;
		free(ptr);
		return data;
	}
	
}

int detachAtEnd(struct Node **head)
{
	if( *head == NULL )	
	{
		return -1;
	}
	
	else
	{
		struct Node * p=*head;
		struct Node * q=p->next;
		
		while(q->next!=NULL)
		{
			q=q->next;
			p=p->next;
		}
		
		p->next=NULL;
		int data=q->data;
		free(q);
		return data;
	}
}

int detachAfterValue(struct Node ** Head ,int value)
{
	struct Node * p= *Head;
	struct Node * q= p->next;
	
	if( *Head == NULL )
	{
		return -1;
	}
	
	else if(p->data==value)
	{
		if(q->next == NULL)
		{
			return -1;
		}
		
		int data = detachAtBegin(Head);
		return data;
	}
	
	else
	{
		while( q->data!=value && q->next != NULL )
		{
			q=q->next;
			p=p->next;
		}
		
		if( q->data==value)
		{
			p->next=q->next;
			int data=q->data;
			free(q);
			return data;
		}
		
		else
			return -1;		

	}
}

int main()
{
	struct Node * Head = NULL ;
	struct Node * first  = createNode();
	struct Node * second = createNode();
	struct Node	* third  = createNode();
	struct Node * fourth = createNode();
	
	initNode(first);
	initNode(second);
	initNode(third);
	initNode(fourth);
	
	first->next=second;
	second->next=third;
	third->next=fourth;
	
	Head=first;
	int index;
	int value;
	
	char ch;
	do{
		
		printf("\n  ****** The Following Opeartions you can perform on List ***** ");
			printf("\n \t 1. Detach At Begin ");
			printf("\n \t 2. Detach At Index ");
			printf("\n \t 3. Detach at End  ");
			printf("\n \t 4. Detach the Node at value \n");
	
			int choice,node;
			printf("\n Enter Which operation you want to perform : ");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:
					node=detachAtBegin(&Head);
					if(node != -1 ){
						printf("\n SUCCESS :- The Node is Detached at Begin ");
						printf("\n DetachedNode [ %d | NULL ]",node);					
						traversal(Head);
					}
					else
						printf("\n FAIL :- Can't  Detach at Begin ");
				break;
				
				case 2:
					printf("\n Enter the index at which You want to detach node : ");
					scanf("%d",&index);
					node=detachAtindex(&Head,index);
					
					if(node != -1)
					{
						printf("\n SUCCESS :- The Node is Detached at Index ");
						printf("\n DetachedNode [ %d | NULL ]",node);					
						traversal(Head);
					}
					else
						printf("\n FAIL :- Can't Detach the node at index");
				break;
				
				case 3:
					node = detachAtEnd(&Head);
					
					if(node != -1 )
					{
						printf("\n SUCCESS :- The Node is detcahed at End ");
						printf("\n DetachedNode [ %d | NULL ]",node);					
						traversal(Head);
					}
					
					else
						printf("\n FAIL :- Can't Detach the node ");
				break;
				
				case 4:
					printf("\n Enter the value at which you want to delete the Node: ");
					scanf("%d",&value);
					
					node=detachAfterValue(&Head,value);
					
					if(node != -1 )
					{
						printf("\n SUCCESS :- The Node is detcahed at End ");
						printf("\n DetachedNode [ %d | NULL ]",node);					
						traversal(Head);
					}
					
					else
						printf("\n FAIL :- Can't Detach the node at value ");
				break;
				
				default:
					printf("\n Invalid Choice");
				
			}
			
			printf("\n Do you want to  perform any opeartions ?(y/n) : ");
			fflush(stdin);
			scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	
	printf("\n THANK YOU :) ");
	
	return 0;
}
