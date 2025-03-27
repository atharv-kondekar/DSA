#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * CreateNode()
{
	struct Node * t;
	t=(struct Node *)malloc(sizeof(struct Node));
	return t;
}

void initnode(struct Node * nn)
{
	int val;
	printf("\n Enter the value : ");
	scanf("%d",&val);
	
	nn->data=val;
	nn->next=NULL;
}


struct Node * Detach_atBegin(struct Node ** head)
{
	struct Node * fristNode;
	
	if( *head == NULL )
	{
		return NULL;
	}
	
	else
	{
		fristNode=*head;
		*head=fristNode->next;
		return(fristNode);
	}
}

void traversal(struct Node  * Ptr)
{
	struct Node * Curnode;
	
	if(Ptr != NULL )
	{
		Curnode=Ptr;
		
		while(Curnode!=NULL)
		{
			printf("\t %d",Curnode->data);
			Curnode=Curnode->next;
		}
	}
}

int main()
{
	struct Node * head = NULL;
	struct Node * temp;
	struct Node * last = NULL;
	
	int n;
	printf("\n Enter the Nodes to Create : ");
	scanf("%d",&n);
	
	int i;
	for(i=0;i<n;i++)
	{
		temp=CreateNode();
		initnode(temp);
		
		//temp->next=head;
		//head=temp;
		if (head == NULL) {
			// If the list is empty, initialize the head
			head = temp;
			last = head;
		} else {
			// Append to the end of the list
			last->next = temp;
			last = temp;
		}
	}
	
	Detach_atBegin(&head);
	traversal(head);
	
		
	return 0;
}
